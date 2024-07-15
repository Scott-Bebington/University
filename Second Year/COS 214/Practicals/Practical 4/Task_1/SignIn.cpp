#include "SignIn.h"
#include <iostream>

SignIn::SignIn(User *user, string Request, Server *server)
{
    /// Checking to see if the user is attempting to sign in
    if (Request == "SignIn")
    {
        /// If the user is attempting to sign in then check to see if the user has a nonse token
        cout << "Attempting to sign in" << endl;
        if (checkNonseToken(server, user) && user->getNonseToken() != "")
        {
            /// If the user has a nonse token then sign the user in
            cout << "User signed in" << endl;
        }
        else
        {
            /// If the user does not have a nonse token then the sign in request has failed
            cout << "sign in request failed" << endl;
        }
    }
    else
    {
        /// If the user is not attempting to sign in then pass the request onto the validate token handler to see if the user wants to retrieve data
        ValidateToken *validateToken = new ValidateToken(user, Request, server);
        validateToken->NoWarning();
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
