#include "ValidateToken.h"
#include <iostream>

ValidateToken::ValidateToken(User *user, string Request, Server *server)
{
    if (Request == "GetData")
    {
        if (checkNonseToken(server, user) && user->getNonseToken() != "")
        {
            cout << "Token validated, getting data" << endl;
            DataHandler *dataHandler = new DataHandler();
        }
        else
        {
            cout << "Token validation failed" << endl;
        }
    }
    else
    {
        cout << "Invalid request" << endl;
    }
}

bool ValidateToken::checkNonseToken(Server *server, User *User1)
{
    for (list<User *>::iterator it = server->Users.begin(); it != server->Users.end(); ++it)
    {
        User *user = *it;
        if (user->getNonseToken() == User1->getNonseToken())
        {
            return true;
        }
    }
    return false;
}
