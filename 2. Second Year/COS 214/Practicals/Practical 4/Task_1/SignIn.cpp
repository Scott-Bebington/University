#include "SignIn.h"
#include <iostream>

SignIn::SignIn(User *user, string Request, Server *server)
{
    if (Request == "SignIn")
    {
        cout << "Attempting to sign in" << endl;
        if (checkNonseToken(server, user))
        {
            if (user->getNonseToken() == "")
            {
                cout << "sign in request failed" << endl;
                return;
            }

            cout << "User signed in" << endl;
        }
        else
        {
            cout << "sign in request failed" << endl;
        }
    }
    else
    {
        ValidateToken *validateToken = new ValidateToken(user, Request, server);
    }
}

string SignIn::generateNonseToken()
{
    return string();
}

bool SignIn::checkNonseToken(Server *server, User *User1)
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
