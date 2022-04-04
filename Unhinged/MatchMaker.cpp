//
//  Matchmaker.cpp
//  Unhinged
//
//  Created by Alan Yu on 3/15/22.
//

#include <stdio.h>
#include "MatchMaker.h"

MatchMaker::MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at)
:m_db(&mdb), m_at(&at)
{

}
std::vector<EmailCount> MatchMaker::IdentifyRankedMatches(std::string email, int threshold) const
{

    std::unordered_set<std::string> dupRemoved;
    const PersonProfile* person = m_db->GetMemberByEmail(email);
    std::vector<EmailCount> f;
    
    //declare key and values
    std::string k = "";
    std::string v = "";
    
    std::string c = ""; //combines everthing
    
    //goes through the person's attribute pairs
    for(int i = 0; i < person -> GetNumAttValPairs(); i++)
    {
        AttValPair avp;
        person -> GetAttVal(i, avp);
        
        std::vector<AttValPair> compatableTraits = m_at->FindCompatibleAttValPairs(avp);
        
        for(int j = 0; j < (int)compatableTraits.size(); j++)
        {
            //add it as a string to the unordered set
            c = compatableTraits[j].attribute + "," + compatableTraits[j].value;
            dupRemoved.insert(c);
        }
    }
    
    //this itterates through an unordered set, takes out the ones that are the same
    std::unordered_set<std::string> actuallyUnique;
    for(std::unordered_set<std::string>::iterator it = dupRemoved.begin(); it != dupRemoved.end(); it++)
    {
        
        int commaIndex = (int)(*it).find(",");
        
        std::string at = (*it).substr(0, commaIndex);
        std::string val = (*it).substr(commaIndex+1, (*it).size());
    
        std::vector<std::string> collision = m_db->FindMatchingMembers(AttValPair(at, val));
        
        for(int k = 0; k < (int) collision.size(); k++)
        {
            if(collision[k] != email)
            {
                actuallyUnique.insert(collision[k]);
            }
        }
    }
    
    for(std::unordered_set<std::string>::iterator it = actuallyUnique.begin(); it != actuallyUnique.end(); it++)
    {
        const PersonProfile* maybeMatch = m_db->GetMemberByEmail(*it);
        int counter = 0;
        
        for(int u = 0; u < (*maybeMatch).GetNumAttValPairs(); u++)
        {
            AttValPair maybe;
            (*maybeMatch).GetAttVal(u, maybe);
            
            std::string sherlock;
            sherlock = maybe.attribute + "," + maybe.value;
            if(dupRemoved.find(sherlock) != dupRemoved.end())
            {
                counter++;
            }
            
        }
        
        if(counter >= threshold)
        {
            f.push_back(EmailCount((*it),counter));
        }
    }
    
    sort(f.begin(), f.end(), fixedComp);
    return f;
    
}
