#ifndef CONSUMERCREATOR_H
#define CONSUMERCREATOR_H

#include "consumer.h"
#include "odataConsumer.h"
#include "jsonConsumer.h"

using namespace std;

class consumerCreator {
private:
    string consumerType;

public:
    void setConsumer(string cons);
    consumer* createConsumer();
};

#endif // CONSUMERCREATOR_H
