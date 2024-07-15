#ifndef VALIDATETOKEN_H
#define VALIDATETOKEN_H

#include <string>
#include "SignIn.h"
#include "DataHandler.h"

using namespace std;

class Server;

class ValidateToken
{
public:
    ValidateToken(User *user, string Request, Server *server);
    bool checkNonseToken(Server *server, User *User1);
    void NoWarning() {}
private:

};

#endif // VALIDATETOKEN_H
