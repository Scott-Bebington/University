#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
public:
    User(string _Name, string _PrivateKey);
    string getNonseToken();
    void setNonseToken(string _NonseToken);
    string getName();
private:
    string Name;
    string PrivateKey;
    string NonseToken;
};

#endif // USER_H