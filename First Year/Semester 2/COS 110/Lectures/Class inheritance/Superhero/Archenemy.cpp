#include "Archenemy.h" 
 
Archenemy::Archenemy(string n, string sp) : Superhero(n, sp) 
{
	cout << "Archenemy " << getName() << " created\n";
}
	
void Archenemy::ruinTheWorld() const
{
	cout << name << " attempted to ruin the world using ";
	cout << superPower << endl;	
}
