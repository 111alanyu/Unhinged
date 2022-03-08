//
//  RadixTree.h
//  Unhinged
//
//  Created by Alan Yu on 3/6/22.
//

#ifndef RadixTree_h
#define RadixTree_h
/*


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
       n -> m_finish = key.substr(1, key.size());
       n -> m_val = value;
       m_dummy.m_children[key.at(0)] = n;
       return;
   }
    
    Node* ptr = m_dummy.m_children[key.at(0)];
    Node* bPtr = ptr;
    int counter = 1;
    std::string rem = key;
    while(counter != key.size())
    {
        if(ptr -> m_finish != "")
        {
            if(rem.substr(counter, ptr -> m_finish.size()) == ptr -> m_finish)
            {
                counter = counter + ptr -> m_finish.size() - 1;
                if (counter == key.size())
                {
                    if(ptr->m_atEnd)
                    {
                        ptr -> m_val = value;
                    }else{
                        ptr -> m_atEnd = true;
                        ptr -> m_val = value;
                    }
                }else{
                    if(ptr -> m_children[key.at(counter)] != nullptr)
                    {
                        ptr = ptr -> m_children[key.at(counter)];
                    }else{
                        Node* l = new Node;
                        l->m_finish = key.substr(counter, key.size() - 1);
                        l-> m_atEnd = true;
                    }
                }
            }else{
                std::string holder = "";
                for(int j = 0; j < ptr -> m_finish.size(); j++)
                {
                    if(ptr -> m_finish.at(j) == key.at(counter + j))
                    {
                        holder += key.at(counter + j);
                    }else
                    {
                        break;
                    }
                }
                
                Node* r = new Node;
                r -> m_finish = holder;
                r -> m_atEnd = false;
                
            }
        }
        
        
        if(ptr -> m_children[key.at(counter)] == nullptr)
        {
            Node* y = new Node;
            y -> m_finish = key.substr(counter + 1, key.size() - counter);
            y -> m_val = value;
            ptr -> m_children[key.at(counter)] = y;
            
            Node z  = new Node;
            z -> m_finish = 
            return;
        }else
        {
            if(ptr == bPtr)
            {
                ptr = ptr -> m_children[counter];
            }else{
                bPtr = ptr;
                ptr = ptr -> m_children[counter];
                
            
        }
            
    }
        counter++;
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

 */
#endif /* RadixTree_h */

