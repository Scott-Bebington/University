#ifndef ODATACONSUMER_H
#define ODATACONSUMER_H

#include "consumer.h"

using namespace std;

class odataConsumer : public consumer {
protected:
    string parseData(string data) override;

private:
    string RemoveTags(string);
    string RemoveEmptyLines(string);
};

#endif // ODATACONSUMER_H
