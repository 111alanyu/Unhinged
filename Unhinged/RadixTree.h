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
    
    Node* ptr =  m_dummy.m_children[key[0]];
    Node* ptrB = m_dummy.m_children[key[0]];
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
    
    
    for(int i = 0; i < key.length(); i++)
    {
        //1. What if we are at the end?
        if(ptr -> m_atEnd)
        {
            
            //1. What if the words are the same?
            if(ptr -> m_finish == key)
            {
                ptr -> m_val = value;
                return;
            }
            
            
            //2. What if they are not?
            
            for(int j = 0; j < ptr -> m_finish.size(); j++)
            {
                if(ptr -> m_finish[j] != key[j])
                {
                    
                    Node* uncle = new Node;
                    uncle -> m_finish = ptr -> m_finish.substr(0, j);
                    
                    ptr -> m_finish = ptr -> m_finish.substr(j, ptr -> m_finish.size());
                    uncle -> m_children[ptr -> m_finish.at(0)] = ptr;
                    ptrB -> m_children[uncle -> m_finish.at(0)] = uncle;
                }
                
            }
            return;
        }
        
        
        //This is if we are dealing with a charachter node
        if(ptr -> m_finish == "")
        {
            //1. Check if the letter is allocated in the array?
            if(ptr -> m_children[key[i]] != nullptr)
            {
                ptr = ptr -> m_children[key[i]];
                if(ptr != ptrB)
                {
                    ptrB = ptrB -> m_children[key[i]];
                }
        
            }
        }else if(ptr -> m_finish != "")
        {
            //Do the substrings match?
              if(ptr -> m_finish == key.substr(i, ptr -> m_finish.size() - 1))
            {
                //this is if the substrings matches
                i = i + ptr -> m_finish.size();
                //this goes forward
            }else{
                for(int k = 0; k < ptr -> m_finish.size(); k++)
                {
                    
                    if(ptr -> m_finish[k] != key[i + k])
                    {
                        
                        Node* temp = new Node;
                        temp = ptr;
                        
                        Node* parent = new Node;
                        parent -> m_finish = ptr -> m_finish.substr(0, k);
                        
                        
                        Node* child1 = new Node; //child 1 is the parm node
                        child1 -> m_finish = key.substr(k, key.size() - 1);
                        child1 -> m_val = value;
                        
                        Node* child2 = new Node; //child 2 is the broken off one
                        child2 -> m_finish = ptr -> m_finish.substr(k, ptr -> m_finish.size());
                        child2 -> m_val = ptr -> m_val;
                        
                        
                        parent -> m_children[child1 -> m_finish[0]] = child1;
                        parent -> m_children[child2 -> m_finish[0]] = child2;
                        
                        ptr -> m_val = 0;
                        ptr -> m_finish = "";
                        ptr -> m_atEnd = false;
                        
                        ptr = parent;
                        
                        
                       
                    }
                }
            }
            
            
        }
        

        //2. What if we are not at the end?
        
        
        
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
