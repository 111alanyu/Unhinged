//
//  PersonProfile.h
//  Unhinged
//
//  Created by Alan Yu on 3/8/22.
//

#ifndef PersonProfile_h
#define PersonProfile_h

#include "provided.h"
#include "RadixTree.h"
#include <map>
#include <vector>
#include <unordered_set>

class PersonProfile
{
public:
    PersonProfile(std::string name, std::string email);
    ~PersonProfile();
    std::string GetName() const;
    std::string GetEmail() const;
    void AddAttValPair(const AttValPair& attval);
    int GetNumAttValPairs() const;
    bool GetAttVal(int attribute_num, AttValPair& attval) const;
    
private:
    std::string m_name;
    std::string m_email;
    RadixTree<std::unordered_set<std::string>> m_tree;
    std::vector<AttValPair> keys;
    int m_numOfPairs;
};

#endif /* PersonProfile_h */
