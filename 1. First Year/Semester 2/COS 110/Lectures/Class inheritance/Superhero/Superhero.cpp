#include "Superhero.h" 

Superhero::Superhero(string n, string sp) : Person(n), superPower(sp) 
{
	cout << "Superhero " << name << " created\n";
}
	
void Superhero::saveTheWorld() const
{
	cout << name << " saved the world using ";
	cout << superPower << endl;
}