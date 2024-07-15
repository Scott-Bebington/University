#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include "lair.h"
#include "bank.h"
#include "Menu.h"
#include "Traps.h"
#include "storyteller.h"
#include "Research.h"

using namespace std;

class engine {
public:
    engine();
    void setupPhase();
private:
    int choice;
    int numTraps;
    lair* myLair;
    bank* myBank;
    Menu* menu;
    storyteller* myStoryteller;
    research* myResearch;
};

#endif  // ENGINE_H