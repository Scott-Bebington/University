#include <iostream>
#include "Organism.h"

using namespace std;

int main(){
	Organism* oggie = new Organism;
	
	cout << "Showing Oggie off" << endl;
  oggie->show();

  cout << "Mutating Oggie" << endl; 
  for (int i = 0; i < 40; i++) {
    cout << ".";
	  oggie->grow();
  }
  cout << endl;
	cout << "Showing Oggie off" << endl;
	oggie->show();
	
  delete oggie;

	return 0;
}
