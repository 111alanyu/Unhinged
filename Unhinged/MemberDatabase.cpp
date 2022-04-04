//
//  MemberDatabase.cpp
//  Unhinged
//
//  Created by Alan Yu on 3/15/22.
//

#include <stdio.h>
#include "MemberDatabase.h"

MemberDatabase::MemberDatabase()
{
    
}

MemberDatabase::~MemberDatabase()
{
    
}

bool MemberDatabase::LoadDatabase(std::string filename)
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
        PersonProfile* nProfile;
        std::string e = "";
        std::string n = "";
        
        int num;
        
        
        n = currLine;
        getline(iFile, currLine, '\n');
        e = currLine;
        
        getline(iFile, currLine, '\n');
        num = stoi(currLine);
        
        nProfile = new PersonProfile(n, e);
        
        for(int i = 0; i < num; i++)
        {
            //goes through each one and adds to k, v, and kp respecitvly
            getline(iFile, currLine, '\n');
            
            std::string k, v, pk;
            
            k = "";
            v = "";
            pk = "";
            
            int j = 0;
            for(j = 0; currLine[j] != ','; j++)
            {
                k += currLine[j];
            }
            
            j = j + 1;
            
            for(; j < (int)currLine.size(); j++)
            {
                v += currLine[j];
            }
            
            pk = k + ',' + v;
            
            std::vector<std::string>* getting = m_AVPtoEmail.search(pk);
            
            if(getting == nullptr)
            {
                std::vector<std::string> inserter;
                inserter.push_back(e);
                m_AVPtoEmail.insert(pk, inserter);
            }else{
                bool flag = false;
                
                for(int r = 0; r < (int)(*getting).size(); r++)
                {
                    if((*getting)[r] == e)
                    {
                        flag = true;
                    }
                }
                
                if(!flag)
                {
                    
                    (*getting).push_back(e);
                }
            }
            
            nProfile -> AddAttValPair(AttValPair(k, v));
        }
        
        PersonProfile** r = m_EmailToPerson.search(e);
        
        if(r == nullptr)
        {
            m_EmailToPerson.insert(e, nProfile);
        }else{
            return false;
        }
        
        getline(iFile, currLine, '\n');
    }
    
    iFile.close(); 
    return true;
}

std::vector<std::string> MemberDatabase::FindMatchingMembers(const AttValPair& input) const
{
    std::vector<std::string> r;
    r.clear();
    
    std::string bloodhound;
    bloodhound = input.attribute + "," + input.value;
    
    std::vector<std::string>* s = m_AVPtoEmail.search(bloodhound);
    
    if(s == nullptr)
    {
        return r;
    }
    
    return *s;
    
}


const PersonProfile* MemberDatabase::GetMemberByEmail(std::string email) const
{
    PersonProfile** pp = m_EmailToPerson.search(email);
    if(pp != nullptr)
    {
        return (*pp);
    }else{
        return nullptr;
    }
    

}
