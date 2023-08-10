#include "Character.h"
#include "Wizard.h"
#include "Fighter.h"
#include "Druid.h"

int main() {
	
	Wizard wizard("Merlin");	
	Fighter knight("Lancelot");	
	Fighter king("Arthur");
	
	cout << endl;
	
	wizard.introduceYourself();	
	knight.introduceYourself();
	king.introduceYourself();
		
	cout << endl;
	
	Druid druid("Miriel", "rowan");
	
	druid.introduceYourself();
	druid.speakToTrees();
		
	cout << endl;
	
	// Why did we not store the wizard and the knights 
	// in a Character object using polymorphism?	
	
	knight.addWeapon("dagger");
	knight.addWeapon("mace");
	
	king.addWeapon("long sword");
	
	knight.fightWith(king);
	king.fightWith(knight);	
		
	cout << endl;
	
	druid.heal(king);
		
	cout << endl;
	
	Character * c = new Wizard("John");
	delete c;
	
	return 0;
}
