#include "User.h"
#include <iostream>

using namespace std;

User::User(string _Name, string _PrivateKey)
{
    Name = _Name;
    PrivateKey = _PrivateKey;
    NonseToken = "";
}

void User::setNonseToken(string _NonseToken)
{
    NonseToken = _NonseToken + PrivateKey;
}

string User::getName()
{
    return this->Name;
}

string User::getNonseToken()
{
    return NonseToken;
}


