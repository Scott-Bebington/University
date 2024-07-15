#include "Server.h"
#include <iostream>

Server::Server()
{
}

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

void Server::AddUser(User *user)
{
    Users.push_back(user);
}

void Server::outputUsers()
{
    for (list<User *>::iterator it = Users.begin(); it != Users.end(); ++it)
    {
        // Access the object through iterator
        User *user = *it;
        cout << "User: " << user->getName() << "\tToken: " << user->getNonseToken() << endl;
    }
}

void Server::makeRequest(User *user, string Request, Server *server)
{
    RequestNonseToken *request = new RequestNonseToken(user, Request, server);
}

User *Server::getUser(string token)
{
    for (list<User *>::iterator it = Users.begin(); it != Users.end(); ++it)
    {
        // Access the object through iterator
        User *user = *it;
        if (user->getNonseToken() == token)
        {
            return user;
        }
        
    }
    return nullptr;
}
