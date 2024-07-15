#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <string>

using namespace std;

class Hero {
public:
    Hero(string, int);
    string getName();
    int getHealth();
    void setName(string);
    void setHealth(int);
    void displayHero();
private:
    string name;
    int health;
    bool isAlive;
};

#endif  // HERO_H