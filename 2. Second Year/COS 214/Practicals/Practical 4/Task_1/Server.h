#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <list>
#include "User.h"
#include "RequestNonseToken.h"

using namespace std;

class Server
{
public:
    Server();
    void AddUser(User *user);
    void outputUsers();
    void makeRequest(User*, string, Server*);
    User* getUser(string);
    list<User*> Users;
private:
    string NonseToken;
    string data = "You got the data";
};

#endif // SERVER_H