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
        Node* temp =  new Node;
        temp -> m_finish = key.substr(1, key.size() - 1);
        temp -> m_val = value;
        m_dummy.m_children[key.at(0)] = temp;
        return;
    }
    
    
    Node* ptr = &m_dummy;
    Node* ptrB = ptr;
    for(int i = 0; i < key.size(); i++)
    {
        //let's say we get to the end of the key value, what do we do?
        
        //this is what happens if the key values are the same
        if(i == key.size() - 1)
        {
            if(ptr -> m_atEnd)
            {
                ptr -> m_val = value;
            } //what about if there is no endpoint yet? -> must implement
            return;
        }
        
        //this is if we are not at the end of the key value yet
        char index = key[i];
        int iIndex = index;
        std::string hol = "";
        
        if(ptr -> m_children[iIndex] == nullptr)
        {
            if(ptr -> m_finish != "")
            {
                for(int k = 0; k < ptr -> m_finish.size(); k++)
                {
                    if(ptr -> m_finish[k] != key[i+k])
                    {
                        break;
                    }else{
                        hol += key[i+k];
                        ptr -> m_finish = ptr -> m_finish.substr(k, ptr -> m_finish.size() - 1);
                    }
                    //what happens if we are at the end?
                }
            
                Node* g = new Node;
                
                g -> m_finish = hol.substr(0, hol.size());
                
                
                
                
                Node* n = new Node;
                n -> m_val = value;
                n -> m_finish = key.substr(i+1, key.size() - 1);
                
                g -> m_children[n -> m_finish.at(0)] = n;
                g -> m_children[ptr -> m_finish.at(0)] = ptr;
                
                ptrB -> m_children[g -> m_finish.at(0)] = g;
                return;
                //this is what happens if we hit a dead end
            }
        }else if(ptr != ptrB)
        {
            ptr = ptr -> m_children[iIndex];
        }else{
            ptr =  ptr -> m_children[iIndex];
            ptrB = ptrB -> m_children[iIndex];
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
