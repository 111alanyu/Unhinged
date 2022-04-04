//
//  MatchMaker.h
//  Unhinged
//
//  Created by Alan Yu on 3/15/22.
//

#ifndef MatchMaker_h
#define MatchMaker_h
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "provided.h"
#include "AttributeTranslator.h"
#include "MemberDatabase.h"


class MatchMaker{
public:

    MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at);
    std::vector<EmailCount> IdentifyRankedMatches(std::string email, int threshold) const;
    ~MatchMaker() {}
private:
    const MemberDatabase* m_db;
    const AttributeTranslator* m_at;
    
    static bool fixedComp(const EmailCount&b, const EmailCount& a)
    {
        if(a.count < b.count)
        {
            return true;
        }else if(a.count == b.count)
        {
            if(a.email > b.email)
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
            

    }
    
};

#endif /* MatchMaker_h */
