#include "CategoryChef.h"

CategoryChef::CategoryChef() {
    this->nextChef = nullptr;
    this->category = 0;
}

CategoryChef::CategoryChef(int cat) {
    this->category = cat;
    this->nextChef = nullptr;
}

/// @brief Order has been delegated to this chef. The chef prepares the meal and sets the meal to the finished meal
/// @param meal 
void CategoryChef::prepare(Meal *_meal) {
    this->meal = _meal;
}

Meal* CategoryChef::getMeal() {
    return this->meal;
}

void CategoryChef::handleRequest(Meal* meal) {
    // cout << "CategoryChef handling request" << endl;
    this->prepare(meal);
}

// void CategoryChef::notify(Table *)
// {
// }

// void CategoryChef::notify(Order*)
// {
// }
