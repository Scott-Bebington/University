#include <iostream>
#include "NeuralNetwork.h"
#include "GeneticProgram.h"

using namespace std;

int main() {
    
    cout << "Neural Netowrk" << endl;
    NeuralNetwork nn = NeuralNetwork(2, 2, 2, 0.2);
    nn.Run();

    cout << endl << endl;
    cout << "Genetic Program" << endl;
    GeneticProgram gp = GeneticProgram();
    gp.Run();
    
    return 0;
}