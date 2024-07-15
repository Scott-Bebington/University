#include "RandomGenerator.h"

#include<iostream>

using namespace std;

RandomGenerator::RandomGenerator(int seed) // specs done
{
	seed = seed;
	srand(seed);
}
	
bool RandomGenerator::randomBool() // specs done
{
	if(rand()%2 == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}