#ifndef CONSUMER_H
#define CONSUMER_H

#include <string>

using namespace std;

class consumer {
public:
    void printData(string data);

protected:
    virtual string parseData(string data) = 0;
};

#endif // CONSUMER_H
