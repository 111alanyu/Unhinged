//
//  AttributeTranslator.cpp
//  Unhinged
//
//  Created by Alan Yu on 3/8/22.
//

#include <stdio.h>
#include <fstream>
#include <vector>
#include "AttributeTranslator.h"
#include "provided.h"

AttributeTranslator::AttributeTranslator()
{
    
}

AttributeTranslator::~AttributeTranslator()
{

}

bool AttributeTranslator::Load(std::string filename)
{
    std::ifstream iFile;
    iFile.open(filename);
    
    if(!iFile)
    {
        return false;
    }
    
    std::string currLine;
    while(getline(iFile, currLine, '\n'))
    {
        
        //create strings for source (at, val) and comp (at, val)
        std::string source_At;
        std::string source_Val;
        
        std::string comp_At;
        std::string comp_Val;
        
        
        int i = 0;
        while(currLine[i] != ',')
        {
            source_At += currLine[i];
        }
        
        i = i + 1;
        
        while(currLine[i] != ',')
        {
            source_Val += currLine[i];
        }
        
        i = i + 1;
        
        while(currLine[i] != ',')
        {
            comp_At += currLine[i];
        }
        
        i = i + 1;
        
        while(currLine[i] != ',')
        {
            comp_Val += currLine[i];
        }
        
        //we will add the source together to make a key
        
        std::string key = source_At + ',' + source_Val;
        
        std::vector<AttValPair>* alreadyIn = m_TransTree.search(key);
        if(alreadyIn == nullptr)
        {
            std::vector<AttValPair> t;
            AttValPair inserter;
            inserter.attribute = comp_At;
            inserter.value = comp_Val;
            
            t.push_back(inserter);
            m_TransTree.insert(key, t);
        }else{
            AttValPair AlInserter;
            AlInserter.attribute = comp_At;
            AlInserter.value = comp_Val;
            alreadyIn -> push_back(AlInserter);
        }
    }
    
    return true;
}

std::vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs( const AttValPair& source) const
{
    std::string searcher;
    searcher = source.attribute + ',' + source.value;
    
    std::vector<AttValPair>* vec = m_TransTree.search(searcher);
    std::vector<AttValPair> ret;
    ret.clear();
    
    
    if(vec == nullptr)
    {
        return ret;
    }else{
        return (*vec);
    }
}
