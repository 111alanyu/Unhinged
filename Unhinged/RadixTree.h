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
    ValueType* search(std::string key) const;
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
ValueType* RadixTree<ValueType>::search(std::string key) const
{
    Node* traverseNode = &m_dummy;
    int elmFound = 0;
    
    while(traverseNode !=  nullptr && !traverseNode -> m_atEnd && elmFound < key.length())
    {
        char cur = key[elmFound];
        int curI = cur;
        if(traverseNode -> m_childrexn[curI] != nullptr)
        {
            if(traverseNode -> m_children[curI] -> m_finish == key.substr(elmFound, traverseNode -> m_children[curI] -> m_finish.size()))
            {
                elmFound += traverseNode -> m_children[curI] -> m_finish.size();
            }
            traverseNode = traverseNode -> m_children[curI];
        }else
        {
            traverseNode = nullptr;
        }
    }
    
    if(traverseNode == nullptr)
    {
        return nullptr;
    }else{
        return traverseNode -> m_val;
    }
}

template <typename ValueType>
void RadixTree<ValueType>::insert(std::string key, const ValueType& value)
{
    if(m_dummy.m_children[key.at(0)] == nullptr)
    {
        Node* n = new Node;
        n -> m_finish = key;
        n -> m_val = value;
        m_dummy.m_children[key.at(0)] = n;
        return;
    }
    Node* ptr = new Node;
    ptr = m_dummy.m_children[key.at(0)];
    
    int i = 0;
    while(i != key.size())
    {

        int j = 0;
        
        //change
        
        //CASE: The key and the node string is the same
        if(ptr -> m_finish == key)
        {
            if(ptr -> m_atEnd)
            {
                ptr -> m_val = value;
            }else{
                ptr -> m_finish = true;
                ptr -> m_val = value;
            }
        }
    
        while(i < key.size() && j < ptr -> m_finish.size())
        {
            if(key.at(i) == ptr -> m_finish.at(j))
            {
                i++;
                j++;
            }else{
                break;
            }
        }
        
        if(j < ptr -> m_finish.size())
        {//we do not reach the end of the ptr
            //we are creating a new node that will be the parent of all these nodes
            Node* stepParent = new Node;
            
            //this is if we go through the whole pass in parameter
            if(i == key.size() - 1)
            {
                stepParent -> m_finish = ptr -> m_finish.substr(0, j);
                stepParent -> m_atEnd = true;
            }else{
                stepParent -> m_finish = ptr -> m_finish.substr(0, j);
                stepParent -> m_atEnd = false;
            }
            
            for(int l = 0; l < ptr -> m_children.size(); l++)
            {
                stepParent -> m_children[l] = ptr -> m_children[l];
            }
            
            ptr = stepParent;
            
            
        }
        
        
        
      
        
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

