#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <string>

using namespace std;

class DataHandler
{
public:
    DataHandler();
    string getData();
    void NoWarning() {}
private:
    string data = "You got the data";
};

#endif // DATAHANDLER_H