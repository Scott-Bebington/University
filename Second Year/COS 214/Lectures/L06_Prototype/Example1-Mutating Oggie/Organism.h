#ifndef ORGANISM_H
#define ORGANISM_H

	#include "Cell.h"

  class Organism  {
	public:
		Organism();
		Organism(int);
		bool grow();
		void show();
		~Organism();
	private:
		Cell** cells;
		int    size;
		int    current;
	};

#endif

