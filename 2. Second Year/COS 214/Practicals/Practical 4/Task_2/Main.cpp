#include <iostream>

#include "Adapter.h"

using namespace std;

int main() {
    Adapter *adapter = new Adapter("SELECT * FROM users");
    cout << adapter->GetNewQuery() << endl;

    cout << "End" << endl;
     
    return 0;
}