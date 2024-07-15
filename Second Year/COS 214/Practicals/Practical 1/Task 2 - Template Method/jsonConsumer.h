#ifndef JSONCONSUMER_H
#define JSONCONSUMER_H

#include "consumer.h"

using namespace std;

class jsonConsumer : public consumer {
protected:
    string parseData(string data) override;

private:
    string RemoveTags(string);
    string RemoveEmptyLines(string);
};

#endif // JSONCONSUMER_H
