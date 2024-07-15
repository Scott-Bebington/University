#include "Fighter.h"

Fighter::Fighter(string n, int h, bool f) : Character(n,h,f)
{
	weaponInventory = new string[SIZE]{""};
	
	cout << "Fighter " << name << " created" << endl;
}

Fighter::~Fighter() 
{
	delete [] weaponInventory;
	cout << "Fighter " << name << " destroyed" << endl;
}

void Fighter::addWeapon(string item)
{
	int i;
	for(i = 0; i < SIZE; i++) {
		if (weaponInventory[i] == "") {
			weaponInventory[i] = item;
			break;
		}
	}
	if(i == SIZE) cout << "Sorry, no space left in inventory!" << endl;
}

void Fighter::fightWith(Character& otherGuy)
{
	for(int i = 0; i < SIZE; i++) {
		if (weaponInventory[i] != "") {
			cout << name << " attacked " << otherGuy.getName();
			cout << " with " << weaponInventory[i] << endl;
			
			otherGuy.setHealth( otherGuy.getHealth() - 1);
		} else break;
	}
	health--;
}

void Fighter::introduceYourself()
{
	cout << "Good day to you, sir! I am " << name;
	cout	<< ", a mighty knight." << endl;
}