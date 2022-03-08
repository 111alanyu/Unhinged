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
    m_at.push_back(attval); //TODO: This is to be changed with insert for the Radix Tree
}

int PersonProfile::GetNumAttValPairs() const
{
    return m_at.size();
}

bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const
{
    if(attribute_num < 0 || attribute_num > GetNumAttValPairs())
    {
        return false;
    }
    
    attval = m_at[attribute_num];
    return true;
}

