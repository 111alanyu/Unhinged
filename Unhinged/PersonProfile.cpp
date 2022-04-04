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
    std::unordered_set<std::string>* r = m_tree.search(attval.attribute);
    
    if(r != nullptr)
    {
        if(r -> find(attval.value) == r->end()){
            keys.push_back(attval);
            r -> insert(attval.value);
        }
    }else{
        keys.push_back(attval);
        std::unordered_set<std::string> in;
        in.insert(attval.value);
        m_tree.insert(attval.attribute, in);
    }
    
    
    
}

int PersonProfile::GetNumAttValPairs() const
{
    return (int) keys.size();
}


bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const
{
    //checks if in bounds
    if(attribute_num < 0 || attribute_num > m_numOfPairs)
    {
        return false;
    }
    
    AttValPair a;
    a.value = keys[attribute_num].value;
    a.attribute = keys[attribute_num].attribute;
    
    attval = a;

    return true;
}


