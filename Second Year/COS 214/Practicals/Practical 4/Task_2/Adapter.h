#ifndef ADAPTER_H
#define ADAPTER_H

#include <iostream>
#include "Target.h"
#include "Adaptee.h"
#include "string"

using namespace std;

// Adapter
class Adapter : public Target {
    public:
    
        Adapter(string);
        virtual string GetNewQuery() override;
    private:
        Adaptee* QueryConverter;
        string newQuery;
};

#endif // ADAPTER_H