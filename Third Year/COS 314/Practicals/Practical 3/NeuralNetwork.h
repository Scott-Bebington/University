#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

class NeuralNetwork
{
public:
    NeuralNetwork(int inputSize, int hiddenSize, int outputSize, double learningRate);
    void Run();
    vector<double> forwardPass(const vector<double> &input);
    void backwardPass(const vector<double> &input, const vector<double> &target);
    void train(const vector<vector<double>> &inputs, const vector<vector<double>> &targets, int epochs);
    vector<string> split(const string &str, char delimiter);
    pair<vector<vector<double>>, vector<vector<double>>> readData(string filename);

    int count = 0;

    // Sigmoid activation function
    double sigmoid(double x)
    {
        return 1.0 / (1.0 + exp(-x));
    }

    // Derivative of sigmoid function
    double sigmoid_derivative(double x)
    {
        double s = sigmoid(x);
        return s * (1 - s);
    }

    int inputSize, hiddenSize, outputSize;
    double learningRate;
    vector<vector<double>> Weights;
    double bias;
    void initializeWeights();

    double randomWeight()
    {
        count++;
        double r = (double)rand() / RAND_MAX;
        // cout << "Random weight: " << r << endl;
        return r;
    }
};