#include "Meal.h"

Meal::Meal()
{
}

void Meal::setNext(Meal *meal)
{
    this->next = meal;
}

Meal *Meal::getNext()
{
    return this->next;
}

Meal* Meal::getMeal() {
    return this;
}

void Meal::add(Meal)
{
}

void Meal::remove(Meal)
{
}

Meal *Meal::getChild(int)
{
    return nullptr;
}

string Meal::getName()
{
    return string();
}

int Meal::getCategory()
{
    return 0;
}

int Meal::getMin()
{
    return 0;
}

int Meal::getMax()
{
    return 0;
}

int Meal::getCost()
{
    return 0;
}

Meal::~Meal()
{
}
