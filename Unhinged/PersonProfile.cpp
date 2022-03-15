//
//  PersonProfile.cpp
//  Unhinged
//
//  Created by Alan Yu on 3/8/22.
//

#include <stdio.h>
#include "PersonProfile.h"

PersonProfile::PersonProfile(std::string name, std::string email)
{
    m_name = name;
    m_email = email;
    m_numOfPairs = 0;
}

std::string PersonProfile::GetName() const
{
    return m_name;
}

std::string PersonProfile::GetEmail() const
{
    return m_email;
}

void PersonProfile::AddAttValPair(const AttValPair& attval)
{
    m_numOfPairs++;
    keys.push_back(attval.attribute);
    m_tree.insert(attval.attribute, attval.value);
    
}

int PersonProfile::GetNumAttValPairs() const
{
    return m_numOfPairs;
}

//TODO: Implement getattVal
bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const
{
    if(attribute_num < 0 || attribute_num > m_numOfPairs)
    {
        return false;
    }
    
    m_tree.search(keys[attribute_num]);
    return true;
}

