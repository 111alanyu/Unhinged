//
//  AttributeTranslator.h
//  Unhinged
//
//  Created by Alan Yu on 3/8/22.
//

#ifndef AttributeTranslator_h
#define AttributeTranslator_h
#include <string>
#include <vector>
#include "provided.h"
#include "RadixTree.h"

class AttributeTranslator
{
public:
    AttributeTranslator();
    ~AttributeTranslator();
    bool Load(std::string filename);
    std::vector<AttValPair> FindCompatibleAttValPairs( const AttValPair& source) const;
    
private:
    RadixTree<std::vector<AttValPair>> m_TransTree;
};
#endif /* AttributeTranslator_h */
