#ifndef ADAPTEE_H
#define ADAPTEE_H

#include <iostream>
#include <string>

using namespace std;

// Adaptee
class Adaptee {
    public:
        Adaptee(string);
        string convertLegacyCode();
        
    private:
        string QueryToConvert;
};

#endif // ADAPTEE_H
