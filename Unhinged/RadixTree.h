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
    /*
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
     */
    
    int i = 0;
    const Node* ptr = new Node;
    ptr = &m_dummy;
    std::cerr<<key.size()<<std::endl;
    while (i < key.size())
    {
        int index = key.at(i);
        
        if(ptr -> m_children[index] != nullptr)
        {
            ptr = ptr -> m_children[index];
            if(ptr -> m_finish == key.substr(i, ptr -> m_finish.size()))
            {
                i += ptr -> m_finish.size();
            }
        }else{
            return nullptr;
        }
    }
    if(i == key.size())
    {
        return &(ptr -> m_val);
    }
    
    return nullptr;
}

template <typename ValueType>
void RadixTree<ValueType>::insert(std::string key, const ValueType& value)
{
    
    if(m_dummy.m_children[key.at(0)] == nullptr)
    {
        Node* n = new Node;
        n -> m_finish = key;
        n -> m_val = value;
        n -> m_atEnd = true;
        m_dummy.m_children[key.at(0)] = n;
        return;
    }
    Node* ptr = new Node;
    ptr = m_dummy.m_children[key.at(0)];
    
    int i = 0;
    while(i < key.size())
    {

        int j = 0;
        //change
        
        //CASE: The key and the node string is the same
        if(ptr -> m_finish == key.substr(i, (int) key.size() - i))
        {
            ptr -> m_val = value;
            if(!ptr -> m_atEnd) //this checks if the node is already marked that it is an "end node"
            {
                ptr -> m_atEnd = true;
            }
            return;
        }
        
        
        //Itterator to see Common Denominator
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
        
        /*
        if(j == 0)
        {
            std::cerr<<"J at 0"<<std::endl;
            Node* input3 = new Node;
            input3 -> m_finish = key.substr(i, key.size() - i);
            return;
        }
         */
        
        
        std::string holder = ptr -> m_finish.substr(0, j);
        //std::cerr<<ptr -> m_finish.size()<<std::endl;
        if(i == key.size()) //case 2: we went through the entire input, and there is more node
        {
            
            Node* stepChild = new Node; //creates stepChild
            stepChild -> m_finish = ptr -> m_finish.substr(j, ptr -> m_finish.size());
            stepChild -> m_val = ptr -> m_val;
            stepChild -> m_atEnd = ptr -> m_atEnd;
            for(int k = 0; k < 128; k++) //copies over the ptr's children to the step child
            {
                stepChild -> m_children[k] = ptr -> m_children[k];
                ptr -> m_children[k] = nullptr;
            }
            
            //resets ptr's value and string
            //string is the common denominator
            ptr -> m_val = value;
            ptr -> m_finish = ptr -> m_finish.substr(0, j);
            
            //after changing ptr to the CMD, set it's child to the step child we made
            ptr -> m_children[stepChild -> m_finish.at(0)] = stepChild;
            ptr -> m_atEnd = true;
            
            
            //M's suggestion
            return;
        }else if(j == ptr -> m_finish.size()){ //case 1: we went through the entire node, and there is more input
            
            if(ptr -> m_children[key.at(i)] != nullptr) //checks if a node starting with the first different letter in key exists at the index
            {
                ptr = ptr -> m_children[key.at(i)];
            }else{
                
                Node* child = new Node;
                child -> m_finish = key.substr(i, key.size());
                child -> m_val = value;
                child -> m_atEnd = true;
                ptr -> m_children[key.at(i)] = child;
                return;
            }
        }else{//case 3: we went through both the node and the input, and we have not reached the end of either of them
            std::cerr<<"Case 3"<<std::endl;
            Node* stepChild = new Node; //create a new node
            stepChild -> m_finish = ptr -> m_finish.substr(j, ptr -> m_finish.size());
            for(int k = 0; k < 128; k++) //copy the children
            {
                stepChild -> m_children[k] = ptr -> m_children[k];
                ptr -> m_children[k] = nullptr;
            }
            stepChild -> m_val = ptr -> m_val; //copy the
            stepChild -> m_atEnd = true;
            
            
            Node* moveInChild = new Node;
            moveInChild -> m_finish = key.substr(i, key.size());
            moveInChild -> m_val = value;
            moveInChild -> m_atEnd = true;

            
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

