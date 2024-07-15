#include <cstdlib>
#include <ctime>
#include "Organism.h"
#include "Cell.h"

//using namespace std;

int const SIZE = 20;

Organism::Organism(){
	size = SIZE;
	cells = new Cell*[size];
	cells[0] = new NormalCell();
	cells[1] = new AbnormalCell();
	current = 1;
}

Organism::Organism(int s){
	size = s;
	cells = new Cell*[size];
	cells[0] = new NormalCell();
	cells[1] = new AbnormalCell();
	current = 1;
}

bool Organism::grow() {
	if (current < size - 1) {
    srand(time(NULL));
		current++;
		cells[current] = cells[rand() % (current - 1)]->divide();
	return true;
	}
	return false;
}

void Organism::show(){
	for (int i = 0; i<=current; i++) {
		cells[i]->print();
	}
	
}

Organism::~Organism() {
	for (int i = 0; i<=current; i++) {
		delete cells[i];
	}
	delete [] cells;
}
