#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
using namespace std;

class Character {
	
 public:
	Character(string, int=100, bool=true);
	virtual ~Character();
 
	int getHealth();
	void setHealth(int);
 
	string getName();
 
	bool isDead();
	bool isFriendly();
 
	virtual void introduceYourself();
 
 protected:
	string name;
	int health;
	bool friendly;
};
 
#endif