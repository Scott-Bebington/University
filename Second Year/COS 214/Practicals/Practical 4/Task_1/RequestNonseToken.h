#ifndef REQUESTNONSETOKEN_H
#define REQUESTNONSETOKEN_H

#include <string>
#include "User.h"
#include "SignIn.h"
#include "Server.h"

using namespace std;

class RequestNonseToken
{
public:
    RequestNonseToken(User *user, string Request, Server *server);
    string generateNonseToken();
    void NoWarning() {}
private:
    string NonseToken;
};

#endif // REQUESTNONSETOKEN_H