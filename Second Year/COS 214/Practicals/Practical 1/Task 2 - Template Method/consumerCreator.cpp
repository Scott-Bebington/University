#include "consumerCreator.h"

using namespace std;

void consumerCreator::setConsumer(string cons) {
    if (cons == "OData" || cons == "JSON") {
        this->consumerType = cons;
    }
}

consumer* consumerCreator::createConsumer() {
    if (consumerType == "OData") {
        return new odataConsumer();
    }
    else if (consumerType == "JSON") {
        return new jsonConsumer();
    }
    else {
        return nullptr;
    }
}
