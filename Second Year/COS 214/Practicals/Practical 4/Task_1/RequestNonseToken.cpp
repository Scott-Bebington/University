#include "RequestNonseToken.h"
#include <iostream>

RequestNonseToken::RequestNonseToken(User *user, string Request, Server *server)
{
    if (Request == "RequestToken")
    {
        cout << "Requesting a nonse token" << endl;
        user->setNonseToken(generateNonseToken());
    }
    else
    {
        SignIn *signIn = new SignIn(user, Request, server);
    }
}

string RequestNonseToken::generateNonseToken()
{
    string token = "";
    const string alphanumeric = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 10; i++)
    {
        token += alphanumeric[rand() % alphanumeric.size()];
    }
    return token;
}
