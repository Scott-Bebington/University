#include "DataHandler.h"
#include <iostream>

DataHandler::DataHandler()
{
    /// Sign in and token validation successfull, retieve data from the database
    cout << getData() << endl;
}

string DataHandler::getData()
{
    return this->data;
}
