#include <iostream>
#include "Adaptee.h"
#include "string"

using namespace std;

Adaptee::Adaptee(string oldQuery)
{
    QueryToConvert = oldQuery;
}

string Adaptee::convertLegacyCode()
{
    cout << "Converting legacy code... (" << QueryToConvert << ")" << endl;
    string *words = new string[2];
    int count = 1;

    for (int i = 0; i < QueryToConvert.length(); i++)
    {
        if (QueryToConvert.substr(i, 4) == "FROM")
        {
            count--;
        }
        words[count] += QueryToConvert[i];
    }

    return words[0] + " " + words[1];
}
