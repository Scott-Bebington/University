#include "Rejected.h"
#include "Context.h"

#include <iostream>

using namespace std;

Rejected::Rejected() 
{
    update();
}

void Rejected::handleChange(Context *c)
{
    
}

std::string Rejected::getState() {
    return "Rejected";
}

void Rejected::update()
{
    cout << "Notification: State Change---------------------------------------------------" << endl;
    cout << "Contract is now in state: Rejected" << endl;
    cout << "-----------------------------------------------------------------------------" << endl << endl;
}
