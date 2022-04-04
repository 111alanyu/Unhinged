//
//  MemberDatabase.h
//  Unhinged
//
//  Created by Alan Yu on 3/15/22.
//
#include <string>
#include <map>
#include <fstream>
#include "provided.h"
#include "PersonProfile.h"


#ifndef MemberDatabase_h
#define MemberDatabase_h
class MemberDatabase
{
public:
    MemberDatabase();
    ~MemberDatabase();
    bool LoadDatabase(std::string filename);
    std::vector<std::string> FindMatchingMembers(const AttValPair& input) const;
    const PersonProfile* GetMemberByEmail(std::string email) const;
    
private:
    
    RadixTree<std::vector<std::string>> m_AVPtoEmail;
    RadixTree<PersonProfile*> m_EmailToPerson;
};

#endif /* MemberDatabase_h */
