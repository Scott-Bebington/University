#include "GA.h"

#include<iostream>

using namespace std;

GA::GA(int populationSize, RandomGenerator* rand, int numGenes, int selectionSize)
{

}

GA::GA(GA* geneticAlgorithm)
{

}

GA::~GA()
{

}

Chromosome** GA::run(FitnessFunction* fitnessFunction)
{

}

double** GA::run(FitnessFunction* fitnessFunction, int numGenerations)
{

}

Chromosome** GA::selection(FitnessFunction* fitnessFunction)
{

}

Chromosome** GA::inverseSelection(FitnessFunction* fitnessFunction)
{

}

Chromosome** GA::crossOver(Chromosome* c1, Chromosome* c2)
{

}

Chromosome* GA::mutate(Chromosome* c1)
{

}

double GA::calculateAvgAccuracy(FitnessFunction* fitnessFunction)
{

}

double GA::calculateStd(FitnessFunction* fitnessFunction)
{

}

double GA::calculateVariance()
{

}

void GA::setPopulation(Chromosome** p)
{
    
}