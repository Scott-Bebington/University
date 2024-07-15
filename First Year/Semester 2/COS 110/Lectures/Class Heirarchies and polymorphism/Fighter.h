#ifndef FIGHTER_H
#define FIGHTER_H

#define SIZE 10

#include "Character.h" 

class Fighter : public Character {
	
public:
	Fighter(string, int = 150, bool = true);
	virtual ~Fighter();

	void addWeapon(string);
	void fightWith(Character&);

	virtual void introduceYourself();
 protected:
	string * weaponInventory;
};

#endif