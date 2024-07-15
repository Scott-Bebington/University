#include "Employee.h"

Employee::Employee() : Person() {
    successor = nullptr;
    employeeNr = id;
}

Employee::~Employee() {
    // delete successor;
}

Employee* Employee::getSuccessor() {
    return successor;
}

void Employee::setSuccessor(Employee *_successor) {
    this->successor = _successor;
}

void Employee::handleRequest(Order *)
{
}

void Employee::notify(Table *)
{
}

void Employee::notify(Order * )
{
}
