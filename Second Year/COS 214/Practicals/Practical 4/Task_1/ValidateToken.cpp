#include "ValidateToken.h"
#include <iostream>

/// @brief Checking to see if the user is attempting to retrieve data, 
///        If the user has a nonse token then validate the token and pass the request onto the data handler
///        If the user does not have a nonse token then the token validation has failed
///        If the user is not attempting to retrieve data then the request is invalid
/// @param user 
/// @param Request 
/// @param server 
ValidateToken::ValidateToken(User *user, string Request, Server *server)
{
    /// 
    if (Request == "GetData")
    {
        /// If the user is attempting to retrieve data then check to see if the user has a nonse token
        if (checkNonseToken(server, user) && user->getNonseToken() != "")
        {
            /// 
            cout << "Token validated, getting data" << endl;
            DataHandler *dataHandler = new DataHandler();
            dataHandler->NoWarning();
        }
        else
        {
            /// If the user does not have a nonse token then the token validation has failed
            cout << "Token validation failed" << endl;
        }
    }
    else
    {
        /// If the user is not attempting to retrieve data then the request is invalid
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
