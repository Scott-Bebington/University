#include "Chromosome.h"

#include<iostream>

using namespace std;

Chromosome::Chromosome(int numGenes, RandomGenerator* rand)
{
    this->numGenes = numGenes;
    if (numGenes < 0)
    {
        numGenes = 0;
    }
    
    genes = new bool(numGenes);
    for (int i = 0; i < numGenes; i++)
    {
        if (rand == NULL)
        {
            genes[i] = false;
        }
        else
        {
            genes[i] = rand;
        }
    }
    
}
	
int Chromosome::setGenes()
{

}

Chromosome::Chromosome(Chromosome* chromosome)
{
    //this->chromosome = chromosome;
}

Chromosome::Chromosome(bool* genes, int numGenes)
{

}

Chromosome::~Chromosome()
{

}

double Chromosome::fitness(FitnessFunction* fitnessFunction, Chromosome* chromosome, int numGenes)
{

}

int Chromosome::getNumGenes()
{

}

Chromosome* Chromosome::crossOver(Chromosome* c2)
{

}

Chromosome* Chromosome::mutate()
{

}

string Chromosome::toString()
{

}

bool* Chromosome::getGenes()
{

}