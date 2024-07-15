#include "RequestNonseToken.h"
#include <iostream>

RequestNonseToken::RequestNonseToken(User *user, string Request, Server *server)
{
    /// Checking to see if the user is requesting a nonse token
    if (Request == "RequestToken")
    {
        /// If the user is requesting a token then generate a nonse token and assign it to the user
        cout << "Requesting a nonse token" << endl;
        user->setNonseToken(generateNonseToken());
    }
    else
    {
        /// If the user is not requesting a token then pass the request onto the signin handler to see if the user wants to sign in
        SignIn *signIn = new SignIn(user, Request, server);
        signIn->NoWarning();
    }
}

string RequestNonseToken::generateNonseToken()
{
    /// Generates a 10 character alphanumeric nonse token
    string token = "";
    const string alphanumeric = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 10; i++)
    {
        token += alphanumeric[rand() % alphanumeric.size()];
    }
    return token;
}
