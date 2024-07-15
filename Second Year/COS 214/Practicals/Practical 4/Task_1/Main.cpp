#include <iostream>
#include "User.h"
#include "Server.h"

using namespace std;

int main() {
    cout << endl;

    Server *serve = new Server();
    User *user1 = new User("Scott", "Scott123456");
    User *user2 = new User("John", "John123456");

    serve->AddUser(user1);
    serve->AddUser(user2);

    serve->makeRequest(user1, "RequestToken", serve);
    serve->makeRequest(user1, "SignIn", serve);
    serve->makeRequest(user1, "GetData", serve);
    // serve->outputUsers();
     
    cout << endl;
    return 0;
}