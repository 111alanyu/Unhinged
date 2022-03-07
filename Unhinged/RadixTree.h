//
//  RadixTree.h
//  Unhinged
//
//  Created by Alan Yu on 3/6/22.
//

#ifndef RadixTree_h
#define RadixTree_h



template <typename ValueType>
class RadixTree
{
public:
    RadixTree();
    ~RadixTree();
    void insert(std::string key, const ValueType& value);
    ValueType* serch(std::string key) const;
private:
    struct Node
    {
        Node* m_children [128];
        std::string m_finish;
        bool m_atEnd = true;
        ValueType m_val;
        

        Node(): m_children()
        {
            
        }
    };
    Node m_dummy;
    
};



template <typename ValueType>
void RadixTree<ValueType>::insert(std::string key, const ValueType& value)
{
    //we do not have to check if the key is nothing
    if(m_dummy.m_children[key[0]] == nullptr)
    {
        std::cerr<<"*"<<std::endl;
        Node* n = new Node;
        n->m_finish = key;
        n->m_val = value;
        m_dummy.m_children[key[0]] = n;
        return;
        //this means that there has been no words starting with the first charachter
    }
    
    Node* ptr =  m_dummy.m_children[key[0]];
    for(int i = 0; i < key.length(); i++)
    {
        //1. What if we are at the end?
        if(ptr -> m_atEnd)
        {
            
            //1. What if the words are the same?
            if(ptr -> m_finish == key)
            {
                ptr -> m_val = value;
            }
            
            
            //2. What if they are not?
            
            for(int j = 0; j < ptr -> m_finish.size(); j++)
            {
                if(ptr -> m_finish[j] != key[j])
                {
                    Node* parent = new Node;
                    parent -> m_finish = ptr -> m_finish.substr(0, j);
                    
                    
                    Node* child1 = new Node; //child 1 is the parm node
                    child1 -> m_finish = key.substr(j, key.size() - 1);
                    child1 -> m_val = value;
                    
                    Node* child2 = new Node; //child 2 is the broken off one
                    child2 -> m_finish = ptr -> m_finish.substr(j, ptr -> m_finish.size());
                    child2 -> m_val = ptr -> m_val;
                    
                    
                    parent -> m_children[child1 -> m_finish[0]] = child1;
                    parent -> m_children[child2 -> m_finish[0]] = child2;
                    
                    ptr -> m_children[parent -> m_finish[0]] = parent;
                    
                    
                    ptr -> m_val = 0;
                    ptr -> m_atEnd = false;

                }
                
            }
        }
        
        //2. What if we are not?
        
        
        
    }
}

template <typename ValueType>
RadixTree<ValueType>::RadixTree()
{
    
}

template <typename ValueType>
RadixTree<ValueType>::~RadixTree()
{
    
}

#endif /* RadixTree_h */
