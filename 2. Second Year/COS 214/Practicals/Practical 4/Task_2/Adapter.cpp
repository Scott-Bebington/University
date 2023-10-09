#include <iostream>
#include "Adapter.h"                                                                                        
#include "string"

using namespace std;

Adapter::Adapter(string query) 
{ 
    QueryConverter = new Adaptee(query); 
};
string Adapter::GetNewQuery() 
{ 
    newQuery = QueryConverter->convertLegacyCode();
    return newQuery;
};

