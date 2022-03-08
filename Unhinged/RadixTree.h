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
        temp -> m_finish = key.substr(1, key.size());
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
        
        if(ptr -> m_children[iIndex] == nullptr)
        {
            
            Node* n = new Node;
            n -> m_val = value;
            n -> m_finish = key.substr(i+1, key.size() - 1);
            
            ptr -> m_children[iIndex ] = n;
            //this is what happens if we hit a dead end
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
