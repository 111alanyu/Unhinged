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
        int v = key.size();
        std::cerr<<"(((" <<key.substr(i, v - i)<<std::endl;
        std::cerr<<")))" <<ptr -> m_finish<<std::endl;
        if(ptr -> m_finish == key.substr(i, v - i))
        {
            if(ptr -> m_atEnd)
            {
                ptr -> m_val = value;
            }else{
                ptr -> m_finish = true;
                ptr -> m_val = value;
            }
            return;
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
        
        if(j == 0)
        {
            std::cerr<<"J at 0"<<std::endl;
            Node* input3 = new Node;
            input3 -> m_finish = key.substr(i, key.size() - i);
            ptrB -> m_children[key.at(i)] = input3;
            return;
        }
        
        std::string holder = ptr -> m_finish.substr(0, j);
        std::cerr<<ptr -> m_finish.size()<<std::endl;
        if(i == key.size()) //case 2: we went through the entire input, and there is more node
        {
            
            Node* stepChild = new Node;
            stepChild -> m_finish = ptr -> m_finish.substr(j, ptr -> m_finish.size());
            
            for(int k = 0; k < 128; k++)
            {
                stepChild -> m_children[k] = ptr -> m_children[k];
                ptr -> m_children[k] = nullptr;
            }
            ptr -> m_finish = ptr -> m_finish.substr(0, j);
            ptr -> m_children[stepChild -> m_finish.at(0)] = stepChild;
            ptr -> m_atEnd = true;
            
            
            //the i is already at the point, so no need to remove the prefix
            std::cerr<<"case 2"<<std::endl;
            
        }else if(j == ptr -> m_finish.size()){ //case 1: we went through the entire node, and there is more input
            std::cerr<<"case 1"<<std::endl;
            
            
            if(ptr -> m_children[key.at(i)])
            {
                ptr = ptr -> m_children[key.at(i)];
            }else{
                
                Node* child = new Node;
                child -> m_finish = key.substr(i, key.size());
                child -> m_val = value;
                ptr -> m_children[key.at(i)] = child;
                return;
            }
        }else{//case 3: we went through both the node and the input, and we have not reached the end of either of them
            std::cerr<<"Case 3"<<std::endl;
            //TODO: This is what we need to fix, we are one too deep
            Node* stepChild = new Node;
            stepChild -> m_finish = ptr -> m_finish.substr(j, ptr -> m_finish.size());
            
            for(int k = 0; k < 128; k++)
            {
                stepChild -> m_children[k] = ptr -> m_children[k];
                ptr -> m_children[k] = nullptr;
            }
            stepChild -> m_val = ptr -> m_val;
            
            Node* moveInChild = new Node;
            moveInChild -> m_finish = key.substr(i, key.size());
            
            ptr -> m_finish = ptr -> m_finish.substr(0, j);
            ptr -> m_children[stepChild -> m_finish.at(0)] = stepChild;
            ptr -> m_children[moveInChild -> m_finish.at(0)] = moveInChild;
            ptr -> m_atEnd = false;
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

