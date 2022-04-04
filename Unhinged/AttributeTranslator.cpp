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
        for(;currLine[i] != ','; i++)
        {
            source_At += currLine[i];
        }
        i++;
        for(;currLine[i] != ','; i++)
        {
            source_Val += currLine[i];
        }
        i++;
        for(;currLine[i] != ','; i++)
        {
            comp_At += currLine[i];
        }
        i++;
        for(;i < currLine.size(); i++)
        {
            comp_Val += currLine[i];
        }
        
        //we will add the source together to make a key
        
        std::string key = source_At + "," + source_Val;
        
        std::vector<AttValPair>* alreadyIn = m_TransTree.search(key);
        if(alreadyIn == nullptr)
        {
            std::vector<AttValPair> t;
            t.push_back(AttValPair(comp_At, comp_Val));
            m_TransTree.insert(key, t);
        }else{
            bool flag = false;
            
            for(int h = 0; h < (int) alreadyIn->size(); h++)
            {
                if(AttValPair(comp_At, comp_Val) == (*alreadyIn)[h])
                {
                    flag = true;
                    break;
                }
            }
            
            if(!flag)
            {
                alreadyIn->push_back(AttValPair(comp_At, comp_Val));
            }
        }
    }
    iFile.close();
    return true;
}

std::vector<AttValPair> AttributeTranslator::FindCompatibleAttValPairs( const AttValPair& source) const
{
    std::string searcher;
    searcher = source.attribute + "," + source.value;
    
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


