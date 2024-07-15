#include "Character.h" 
 
Character::Character(string n, int h, bool f)
	: name(n), health(h), friendly(f) 
{
	cout << "Character " << name << " created" << endl;
}
		
Character::~Character()	
{
	cout << "Character " << name << " destroyed" << endl;
}

int Character::getHealth()
{
	return health;
}

void Character::setHealth(int h)
{
	health = h;
}

string Character::getName()
{
	return name;
}

bool Character::isDead()
{
	if(health <= 0) return true;
	else return false;
}

bool Character::isFriendly()
{
	return friendly;
}

void Character::introduceYourself()
{	
	cout << "Hello! My name is " << name << "." << endl;
}