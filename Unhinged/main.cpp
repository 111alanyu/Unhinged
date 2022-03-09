#include <iostream>
#include "RadixTree.h"

using namespace std;
void testRT3() {
    RadixTree<std::string> tree;
    string val;

    tree.insert("Ahart@gmail.com", "1");
    
    val = *(tree.search("Ahart@gmail.com"));
    assert(val == "1");
    

    tree.insert("AmJuare@gmail.com", "2");
    
    
    val = *(tree.search("AmJuare@gmail.com"));
    assert(val == "2");
    val = *(tree.search("Ahart@gmail.com"));
    assert(val == "1");
     
    
    tree.insert("AmH74@gmail.com", "3");
    
    
    val = *(tree.search("AmH74@gmail.com"));
    assert(val == "3");
    val = *(tree.search("AmJuare@gmail.com"));
    assert(val == "2");
    val = *(tree.search("Ahart@gmail.com"));
    assert(val == "1");
     
}


int main()
{
    string sad = "a";
    string jenny = sad.substr(1,1);
    
    
    RadixTree<int> r;
    
    r.insert("carpet", 4);
    r.insert("car",3);
    
    r.insert("carpeter", 5);
    
    
    r.insert("carppy", 10);
    
    r.insert("titty", 11);
    r.insert("titts", 15);
    r.insert("titty", 20);
    
    r.insert("titt", -69);
    
    //testRT3();
    

    std::cout<<"Hello World"<<std::endl;
    return 0;
}




//main.cpp

/*
#include "PersonProfile.h"
#include "AttributeTranslator.h"
#include "MemberDatabase.h"
#include "MatchMaker.h"
#include "provided.h"
#include <iostream>
#include <string>
#include <vector>

const std::string MEMBERS_FILE    = "members.txt";
const std::string TRANSLATOR_FILE = "translator.txt";

bool findMatches(const MemberDatabase& mdb, const AttributeTranslator& at);

int main() {
    MemberDatabase mdb;
    if (!mdb.LoadDatabase(MEMBERS_FILE))
    {
        std::cout << "Error loading " << MEMBERS_FILE << std::endl;
        return 1;
    }
    AttributeTranslator at;
    if (!at.Load(TRANSLATOR_FILE))
    {
        std::cout << "Error loading " << TRANSLATOR_FILE << std::endl;
        return 1;
    }

    while (findMatches(mdb, at))
        ;

    std::cout << "Happy dating!" << std::endl;
}

bool findMatches(const MemberDatabase& mdb, const AttributeTranslator& at)
{
      // Prompt for email
    std::string email;
    const PersonProfile* pp;
    for (;;) {
        std::cout << "Enter the member's email for whom you want to find matches: ";
        std::getline(std::cin, email);
        if (email.empty())
            return false;
        pp = mdb.GetMemberByEmail(email);
        if (pp != nullptr)
            break;
        std::cout << "That email is not in the member database." << std::endl;
    }

      // Show member's attribute-value pairs
    std::cout << "The member has the following attributes:" << std::endl;
    for (int k = 0; k != pp->GetNumAttValPairs(); k++) {
        AttValPair av;
        pp->GetAttVal(k, av);
        std::cout << av.attribute << " --> " << av.value << std::endl;
    }

      // Prompt user for threshold
    int threshold;
    std::cout << "How many shared attributes must matches have? ";
    std::cin >> threshold;
    std::cin.ignore(10000, '\n'); 

      // Print matches and the number of matching translated attributes
    MatchMaker mm(mdb, at);
    std::vector<EmailCount> emails = mm.IdentifyRankedMatches(email, threshold);
    if (emails.empty())
        std::cout << "No member was a good enough match." << std::endl;
    else {
        std::cout << "The following members were good matches:" << std::endl;;
        for (const auto& emailCount : emails) {
            const PersonProfile* pp = mdb.GetMemberByEmail(emailCount.email);
            std::cout << pp->GetName() << " at " << emailCount.email << " with "
                      << emailCount.count << " matches!" << std::endl;
        }
    }
    std::cout << std::endl;
    return true;
}

*/
