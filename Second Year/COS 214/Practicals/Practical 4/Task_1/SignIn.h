#ifndef SIGNIN_H
#define SIGNIN_H

#include <string>
#include "RequestNonseToken.h"
#include "ValidateToken.h"

using namespace std;

class Server;

class SignIn
{
public:
    SignIn(User *user, string Request, Server *server);
    string generateNonseToken();
    bool checkNonseToken(Server *server, User *User1);
    void NoWarning() {}
private:
    string NonseToken;
};

#endif // SIGNIN_H