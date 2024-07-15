 #include "Wizard.h" 
 
Wizard::Wizard(string n, int h, bool f, int m)
	: Character(n,h,f), mana(m) 
{
	magicInventory = new string[MAGIC_SIZE];
	
	for(int i = 0; i < MAGIC_SIZE; i++) {
		magicInventory[i] = "";
	}
	
	cout << "Wizard " << name << " created" << endl;
}
		
Wizard::~Wizard()
{
	delete [] magicInventory;
	cout << "Wizard " << name << " destroyed" << endl;
}

int Wizard::getMana() { return mana; }
	
void Wizard::setMana(int m) { mana = m; }

void Wizard::castSpell(Character& character)
{
	if(mana > 0)
	{
		if(character.isFriendly())
			character.setHealth(character.getHealth() + 1);
		else
			character.setHealth(character.getHealth() - 1);
		mana--;		
	}
}


void Wizard::addMagicItem(string item)
{
	int i;
	for(i = 0; i < MAGIC_SIZE; i++) {
		if (magicInventory[i] == "") {
			magicInventory[i] = item;
			break;
		}
	}
	if(i == MAGIC_SIZE) cout << "Sorry, no space left in inventory!" << endl;
}

void Wizard::introduceYourself()
{
	cout << "Greetings, traveller! I am " << name;
	cout << ", a great mage." << endl;
}