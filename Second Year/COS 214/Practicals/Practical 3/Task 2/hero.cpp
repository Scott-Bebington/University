#include <iostream>
#include <string>
#include "hero.h"

Hero::Hero(string name, int health)
{
    this->name = name;
    this->health = health;
    this->isAlive = true;
}

string Hero::getName() {
    return name;
}

int Hero::getHealth() {
    return health;
}

void Hero::setName(string name) {
    this->name = name;
}

void Hero::setHealth(int health) {
    this->health = health;
    if(health <= 0)
    {
        this->isAlive = false;
    }
}

void Hero::displayHero() {
    cout << "Name:\t" << name << endl;
    cout << "Health:\t" << health << endl;
}
