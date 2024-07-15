#include "DataHandler.h"
#include <iostream>

DataHandler::DataHandler()
{
    cout << getData() << endl;
}

string DataHandler::getData()
{
    return this->data;
}
