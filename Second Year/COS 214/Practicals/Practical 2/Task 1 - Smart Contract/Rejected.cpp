#include "Rejected.h"
#include "Context.h"

#include <iostream>

using namespace std;

Rejected::Rejected() 
{

}

void Rejected::handleChange(Context *c)
{
    
}

std::string Rejected::getState() {
    return "Rejected";
}

void Rejected::update()
{
}
