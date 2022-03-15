//
//  AttributeTranslator.cpp
//  Unhinged
//
//  Created by Alan Yu on 3/8/22.
//

#include <stdio.h>
#include <fstream>
#include "AttributeTranslator.h"

AttributeTranslator::AttributeTranslator()
{
    
}

AttributeTranslator::~AttributeTranslator()
{
    
}

bool AttributeTranslator::Load(std::string filename)
{
    std::string line;
    std::ifstream file;
    
    file.open(filename);
    
    while(file >> line)
    {
        std::string Key;
        int i = 0;
        
        i = (int) line.find(",");
        Key += line.substr(0, i + 1);
        line = line.substr(i + 1);
        
        i = (int)line.find(",");
        Key += line.substr(0, i);
        line = line.substr(i + 1);
        
        
    }
    return false; //TODO: change later
}
