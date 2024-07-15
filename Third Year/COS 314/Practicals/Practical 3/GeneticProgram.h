#pragma once

#include <vector>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <sstream>
#include <fstream>
#include <chrono>

using namespace std;

enum NodeType
{
    FUNCTION,
    TERMINAL
};

struct Node
{
    NodeType type;
    double value;
    char function;
    Node *left;
    Node *right;

    Node(NodeType t, double v = 0, char f = '\0') : type(t), value(v), function(f), left(nullptr), right(nullptr) {}
};

class GeneticProgram
{
private:
    const int populationSize = 100;
    const int maxDepth = 6;
    const int generations = 50;
    const double mutationRate = 0.3;

public:
    GeneticProgram();
    double evaluate(Node *node, const vector<double> &inputs);
    vector<double> calculateMetrics(Node *bestTree, const vector<vector<double>> &testInputs, const vector<double> &testOutputs);
    Node *generateRandomTree(int depth);
    vector<Node *> initializePopulation(int populationSize, int maxDepth);
    double fitness(Node *tree, const vector<vector<double>> &data, const vector<double> &outputs);
    Node *tournamentSelection(const vector<Node *> &population, const vector<double> &fitnesses);
    Node *deepCopy(Node *node);
    Node *crossover(Node *parent1, Node *parent2);
    void mutate(Node *node, int maxDepth);
    void ReplacePopulation(vector<Node *> &population, const vector<vector<double>> &data, const vector<double> &outputs, int generations, double mutationRate);
    vector<string> split(const string &s, char delimiter);
    pair<vector<vector<double>>, vector<double>> readData(const string &filename);
    void Run();
    Node *getBestTree(vector<Node *> population, const vector<vector<double>> &testInputs, const vector<double> &testOutputs);
};
