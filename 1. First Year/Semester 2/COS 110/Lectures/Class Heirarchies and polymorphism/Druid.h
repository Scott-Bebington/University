#ifndef DRUID_H
#define DRUID_H

#include "Wizard.h"

class Druid : public Wizard {
	
public:
	Druid(string, string, int = 50, bool = true, int = 500);
	virtual ~Druid();
	void speakToTrees();

	virtual void introduceYourself();
	virtual void heal(Character&);

 protected:
	string tree;
};

#endif
