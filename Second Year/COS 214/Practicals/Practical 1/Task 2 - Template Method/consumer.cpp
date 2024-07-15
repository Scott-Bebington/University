#include "consumer.h"
#include <iostream>

using namespace std;

void consumer::printData(string data) 
{
    string parsedData = parseData(data);
    cout << parsedData << endl;
}
