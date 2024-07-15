#ifndef HANDLER_H
#define HANDLER_H

#include <string>
#include "Server.h"

using namespace std;

class Server;

class Handler
{
public:
    Handler() {};
    virtual void NextHandler(Handler *handler) = 0;
    virtual void Request(User *user, string Request, Server *server) = 0;
    virtual ~Handler() {}

protected:
    Handler *handler;
};

#endif // HANDLER_H