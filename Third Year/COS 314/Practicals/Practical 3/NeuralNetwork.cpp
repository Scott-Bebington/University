#include "NeuralNetwork.h"
#include "../../../../../../../../../../usr/include/c++/11/bits/algorithmfwd.h"

using namespace std;

NeuralNetwork::NeuralNetwork(int inputSize, int hiddenSize, int outputSize, double learningRate)
    : inputSize(inputSize), hiddenSize(hiddenSize), outputSize(outputSize), learningRate(learningRate)
{
    initializeWeights();
}

void NeuralNetwork::Run()
{
    // srand(1);
    srand(123456);

    pair<vector<vector<double>>, vector<vector<double>>> data = readData("traindata.txt");
    vector<vector<double>> inputs = data.first;
    vector<vector<double>> targets = data.second;

    // Shuffle the inputs
    random_shuffle(inputs.begin(), inputs.end());

    train(inputs, targets, 10);

    pair<vector<vector<double>>, vector<vector<double>>> testdata = readData("testdata.txt");
    inputs = testdata.first;
    targets = testdata.second;
    cout << "Testing the neural network" << endl;

    int TP = 0, TN = 0, FP = 0, FN = 0;

    for (size_t i = 0; i < inputs.size(); ++i)
    {
        vector<double> output = forwardPass(inputs[i]);
        double predictedOutput = output[0];

        // Threshold the predicted output
        if (predictedOutput > 0.5)
        {
            predictedOutput = 1;
        }
        else
        {
            predictedOutput = 0;
        }

        double actualOutput = targets[i][0];

        if (predictedOutput == actualOutput)
        {
            if (predictedOutput == 1)
            {
                ++TP;
            }
            else
            {
                ++TN;
            }
        }
        else
        {
            if (predictedOutput == 1)
            {
                ++FP;
            }
            else
            {
                ++FN;
            }
        }

        
    }

    double accuracy = static_cast<double>(TP + TN) / (TP + TN + FP + FN);
    double specificity = static_cast<double>(TN) / (TN + FP);
    double sensitivity = static_cast<double>(TP) / (TP + FN);
    double precision = static_cast<double>(TP) / (TP + FP);
    double fMeasure = 2 * (precision * sensitivity) / (precision + sensitivity);

    cout << "Accuracy: " << accuracy * 100 << "%" << endl;
    cout << "Specificity: " << specificity << endl;
    cout << "Sensitivity: " << sensitivity << endl;
    cout << "F-measure: " << fMeasure << endl;
}

void NeuralNetwork::initializeWeights()
{
    // cout << "Initializing weights" << endl;
    // Initialize weights
    Weights.push_back(vector<double>(inputSize * hiddenSize));
    Weights.push_back(vector<double>(hiddenSize * outputSize));

    for (size_t i = 0; i < Weights.size(); ++i)
    {
        for (size_t j = 0; j < Weights[i].size(); ++j)
        {
            Weights[i][j] = randomWeight();
        }
    }
}

vector<double> NeuralNetwork::forwardPass(const vector<double> &input)
{
    vector<double> hiddenLayer(hiddenSize);
    vector<double> outputLayer(outputSize);

    // Calculate the hidden layer
    for (int i = 0; i < hiddenSize; ++i)
    {
        double sum = bias * Weights[0][i];
        for (int j = 0; j < inputSize; ++j)
        {
            sum += input[j] * Weights[0][i * inputSize + j];
        }
        hiddenLayer[i] = sigmoid(sum);
    }

    // Calculate the output layer
    for (int i = 0; i < outputSize; ++i)
    {
        double sum = bias * Weights[1][i];
        for (int j = 0; j < hiddenSize; ++j)
        {
            sum += hiddenLayer[j] * Weights[1][i * hiddenSize + j];
        }
        outputLayer[i] = sigmoid(sum);
    }

    return outputLayer;
}

void NeuralNetwork::backwardPass(const vector<double> &input, const vector<double> &target)
{
    vector<double> hiddenLayer(hiddenSize);
    vector<double> outputLayer(outputSize);

    // Calculate the hidden layer
    for (int i = 0; i < hiddenSize; ++i)
    {
        double sum = 0.0;
        for (int j = 0; j < inputSize; ++j)
        {
            sum += input[j] * Weights[0][i * inputSize + j];
        }
        hiddenLayer[i] = sigmoid(sum);
    }

    // Calculate the output layer
    for (int i = 0; i < outputSize; ++i)
    {
        double sum = 0.0;
        for (int j = 0; j < hiddenSize; ++j)
        {
            sum += hiddenLayer[j] * Weights[1][i * hiddenSize + j];
        }
        outputLayer[i] = sigmoid(sum);
    }

    // Calculate the output layer error
    vector<double> outputError(outputSize);
    for (int i = 0; i < outputSize; ++i)
    {
        outputError[i] = (target[i] - outputLayer[i]) * sigmoid_derivative(outputLayer[i]);
    }

    // Calculate the hidden layer error
    vector<double> hiddenError(hiddenSize);
    for (int i = 0; i < hiddenSize; ++i)
    {
        double sum = 0.0;
        for (int j = 0; j < outputSize; ++j)
        {
            sum += Weights[1][j * hiddenSize + i] * outputError[j];
        }
        hiddenError[i] = sum * sigmoid_derivative(hiddenLayer[i]);
    }

    // Update the weights of the output layer
    for (int i = 0; i < outputSize; ++i)
    {
        for (int j = 0; j < hiddenSize; ++j)
        {
            Weights[1][i * hiddenSize + j] += learningRate * outputError[i] * hiddenLayer[j];
        }
    }

    for (int i = 0; i < hiddenSize; ++i)
    {
        for (int j = 0; j < inputSize; ++j)
        {
            Weights[0][i * inputSize + j] += learningRate * hiddenError[i] * input[j];
        }
    }

    // Update the bias
    bias += learningRate * hiddenError[0];

    // output the output layer error
    // cout << "Output layer error: " << outputError[0] << endl;
}

void NeuralNetwork::train(const vector<vector<double>> &inputs, const vector<vector<double>> &targets, int epochs)
{
    for (int epoch = 0; epoch < epochs; ++epoch)
    {
        // cout << "Epoch " << epoch << endl;
        // cout << "Inputs size: " << inputs.size() << endl;
        for (size_t i = 0; i < inputs.size(); ++i)
        {
            // cout << "Forward pass" << endl;
            forwardPass(inputs[i]);
            // cout << "Backward pass" << endl;
            backwardPass(inputs[i], targets[i]);
        }
    }
}

vector<string> NeuralNetwork::split(const string &str, char delimiter)
{
    vector<string> tokens;
    string token;
    stringstream ss(str); // Use a stringstream to parse the string

    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token); // Store each token in the vector
    }

    return tokens;
}

pair<vector<vector<double>>, vector<vector<double>>> NeuralNetwork::readData(string filename)
{
    ifstream file(filename);
    string line;
    vector<vector<double>> inputs;
    vector<vector<double>> targets;

    while (getline(file, line))
    {
        vector<string> tokens = split(line, ',');
        vector<double> input;
        vector<double> target;

        for (size_t i = 0; i < tokens.size(); ++i)
        {
            input.push_back(stod(tokens[i]));
        }
        targets.push_back({input.back()});
        input.pop_back();
        inputs.push_back(input);
    }

    return make_pair(inputs, targets);
}

