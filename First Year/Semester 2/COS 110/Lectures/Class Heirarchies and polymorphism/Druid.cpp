#include "Druid.h"

Druid::Druid(string n, string t, int h, bool f, int m)
	: tree(t), Wizard(n, h, f, m)
{
	cout << "Druid " << name << " created" << endl;
}

Druid::~Druid()
{
	cout << "Druid " << name << " destroyed" << endl;
}

void Druid::speakToTrees()
{
	cout << name << " speaks to a " << tree << " tree" << endl;
}

void Druid::introduceYourself()
{
	cout << "Hi! I am " << name;
	cout << ", and I love trees." << endl;
}

void Druid::heal(Character& character)
{
	if(mana > 0)
	{
		character.setHealth( character.getHealth() + 1 );
		mana--;	
		cout << name << " healed " << character.getName() << endl;
	}
}