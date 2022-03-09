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
    Node* ptrB = &m_dummy;
    
    int i = 0;
    while(i < key.size())
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
        
        std::string holder = ptr -> m_finish.substr(0, j);
        std::cerr<<ptr -> m_finish.size()<<std::endl;
        if(i == key.size()) //case 2: we went through the entire input, and there is more node
        {
            //I have this the wrong way
            Node* input2 = new Node;
            input2 -> m_finish = holder;
            input2 -> m_val = value;
            
            ptrB -> m_children[holder.at(0)] = input2;
            
            ptr -> m_finish = ptr -> m_finish.substr(j, ptr -> m_finish.size() - j);
            input2 -> m_children[ptr -> m_finish.at(0)] = ptr;
            
            //the i is already at the point, so no need to remove the prefix
            std::cerr<<"case 2"<<std::endl;
            
        }else if(j == ptr -> m_finish.size()){ //case 1: we went through the entire node, and there is more input
            std::cerr<<"case 1"<<std::endl;
            std::cerr<<key.at(i)<<std::endl;
            if(ptr -> m_children[key.at(i)] == nullptr)
            {
                Node* input = new Node();
                input -> m_finish = key.substr(j, key.size() - j);
                ptr -> m_children[input -> m_finish.at(0)] = input;
                return;
            }else{
                std::cerr<<"FLAG1"<<std::endl;
                if(ptrB == ptr)
                {
                    ptr =  ptr -> m_children[key.at(i)];
                }else{
                    ptrB = ptr;
                    ptr = ptr -> m_children[key.at(i)];
                }
               
               
            }
        }else{//case 3: we went through both the node and the input, and we have not reached the end of either of them
            std::cerr<<"case 3"<<std::endl;
            Node* input2 = new Node;
            input2 -> m_finish = holder;
            input2 -> m_val = value;
            
            ptrB -> m_children[holder.at(0)] = input2;
            
            ptr -> m_finish = ptr -> m_finish.substr(j, ptr -> m_finish.size() - j);
            input2 -> m_children[ptr -> m_finish.at(0)] = ptr;
            
            return;
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

