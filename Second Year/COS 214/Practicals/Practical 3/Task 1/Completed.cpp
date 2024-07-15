#include "Completed.h"
#include "Context.h"

#include <iostream>

using namespace std;

Completed::Completed() 
{
    update();
}

void Completed::handleChange(Context *c)
{
    
}

std::string Completed::getState() {
    return "Completed";
}

void Completed::update()
{
    cout << "Notification: State Change---------------------------------------------------" << endl;
    cout << "Contract is now in state: Completed\033[0m" << endl;
    cout << "-----------------------------------------------------------------------------" << endl << endl;
}
