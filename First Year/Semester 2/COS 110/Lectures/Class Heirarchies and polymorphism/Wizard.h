#ifndef WIZARD_H
#define WIZARD_H

#define MAGIC_SIZE 10

#include "Character.h" 

class Wizard : public Character {
	
public:
	Wizard(string, int = 50, bool = true, int = 500);
	virtual ~Wizard();
	int getMana();
	void setMana(int);

	virtual void castSpell(Character&);

	void addMagicItem(string);

	virtual void introduceYourself();
 protected:
	int mana;
	string * magicInventory;
};

#endif