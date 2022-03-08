//
//  PersonProfile.h
//  Unhinged
//
//  Created by Alan Yu on 3/8/22.
//

#ifndef PersonProfile_h
#define PersonProfile_h

#include "provided.h"
#include <map>
#include <vector>

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
    std::vector<AttValPair> m_at;
};

#endif /* PersonProfile_h */
