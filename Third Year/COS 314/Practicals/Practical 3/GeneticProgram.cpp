#include "GeneticProgram.h"

GeneticProgram::GeneticProgram()
{
}

double GeneticProgram::evaluate(Node *node, const vector<double> &inputs)
{
    if (node->type == TERMINAL)
    {
        return node->value;
    }
    double leftValue = evaluate(node->left, inputs);
    double rightValue = evaluate(node->right, inputs);
    switch (node->function)
    {
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    case '*':
        return leftValue * rightValue;
    case '/':
        return rightValue != 0 ? leftValue / rightValue : 1;
    default:
        return 0;
    }
}

vector<double> GeneticProgram::calculateMetrics(Node *bestTree, const vector<vector<double>> &testInputs, const vector<double> &testOutputs)
{
    int TP = 0, TN = 0, FP = 0, FN = 0;
    for (size_t i = 0; i < testInputs.size(); ++i)
    {
        double predictedOutput = evaluate(bestTree, testInputs[i]);

        // Threshold the predicted output
        if (predictedOutput > 0.5)
        {
            predictedOutput = 1;
        }
        else
        {
            predictedOutput = 0;
        }

        double actualOutput = testOutputs[i];
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
    return {accuracy, specificity, sensitivity, precision, fMeasure};
}


Node* GeneticProgram::generateRandomTree(int depth)
{
    if (depth == 0)
    {
        return new Node(TERMINAL, rand() % 10);
    }
    Node* node = new Node(FUNCTION, 0, "+-*/"[rand() % 4]);
    node->left = generateRandomTree(depth - 1);
    node->right = generateRandomTree(depth - 1);
    return node;
}

vector<Node *> GeneticProgram::initializePopulation(int populationSize, int maxDepth)
{
    vector<Node *> population;
    for (int i = 0; i < populationSize; ++i)
    {
        // generate a random number between 2 and maxDepth
        int depth = 2 + rand() % (maxDepth - 1);
        population.push_back(generateRandomTree(depth));
    }
    return population;
}

double GeneticProgram::fitness(Node *tree, const vector<vector<double>> &data, const vector<double> &outputs)
{
    double totalError = 0;
    for (size_t i = 0; i < data.size(); ++i)
    {
        double result = evaluate(tree, data[i]);
        totalError += pow(result - outputs[i], 2);
    }
    return totalError / data.size();
}

Node *GeneticProgram::tournamentSelection(const vector<Node *> &population, const vector<double> &fitnesses)
{
    int tournamentSize = 5;
    Node *best = population[rand() % population.size()];
    double bestFitness = fitnesses[0];
    for (int i = 1; i < tournamentSize; ++i)
    {
        Node *contender = population[rand() % population.size()];
        double contenderFitness = fitnesses[i];
        if (contenderFitness < bestFitness)
        {
            best = contender;
            bestFitness = contenderFitness;
        }
    }
    return best;
}

Node *GeneticProgram::deepCopy(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    Node *newNode = new Node(node->type, node->value, node->function);
    newNode->left = deepCopy(node->left);
    newNode->right = deepCopy(node->right);
    return newNode;
}

Node *GeneticProgram::crossover(Node *parent1, Node *parent2)
{
    if (rand() % 2 == 0)
    {
        return deepCopy(parent1);
    }
    else if (parent1->type == TERMINAL || parent2->type == TERMINAL)
    {
        return deepCopy(parent1->type == TERMINAL ? parent1 : parent2);
    }
    else
    {
        Node *node = new Node(FUNCTION, 0, parent2->function);
        node->left = crossover(parent1->left, parent2->left);
        node->right = crossover(parent1->right, parent2->right);
        return node;
    }
}

void GeneticProgram::mutate(Node *node, int maxDepth)
{
    if (node->type == FUNCTION && maxDepth > 0)
    {
        if (rand() % 2 == 0)
        {
            node->function = "+-*/"[rand() % 4];
        }
        else 
        {
            node->type = TERMINAL;
            node->value = rand() % 10;
        }
    }
    else if (node->type == TERMINAL && maxDepth > 0)
    {
        if (rand() % 2 == 0) // 50% chance to grow the tree
        {
            node->type = FUNCTION;
            node->function = "+-*/"[rand() % 4];
            node->left = generateRandomTree(maxDepth - 1);
            node->right = generateRandomTree(maxDepth - 1);
        }
        else
        {
            node->value = rand() % 10;
        }
    }
}

void GeneticProgram::ReplacePopulation(vector<Node *> &population, const vector<vector<double>> &data, const vector<double> &outputs, int generations, double mutationRate)
{
    for (int g = 0; g < generations; ++g)
    {
        vector<double> fitnesses;
        for (Node *tree : population)
        {
            fitnesses.push_back(fitness(tree, data, outputs));
        }

        vector<Node *> newPopulation;
        for (size_t i = 0; i < population.size(); ++i)
        {
            Node *parent1 = tournamentSelection(population, fitnesses);
            Node *parent2 = tournamentSelection(population, fitnesses);
            Node *child = crossover(parent1, parent2);
            if (rand() / double(RAND_MAX) < mutationRate)
            {
                mutate(child, 3);
            }
            newPopulation.push_back(child);
        }

        for (Node *tree : population)
        {
            delete tree;
        }
        population = newPopulation;
    }
}

vector<string> GeneticProgram::split(const string &s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

pair<vector<vector<double>>, vector<double>> GeneticProgram::readData(const string &filename)
{
    ifstream file(filename);
    vector<vector<double>> inputs;
    vector<double> outputs;

    if (!file.is_open())
    {
        cout << "Unable to open file" << endl;
        return make_pair(inputs, outputs);
    }

    string line;
    getline(file, line);
    while (getline(file, line))
    {
        vector<string> tokens = split(line, ',');
        vector<double> input;
        for (size_t i = 0; i < tokens.size() - 1; i++)
        {
            input.push_back(stod(tokens[i]));
        }
        inputs.push_back(input);
        outputs.push_back(stod(tokens.back()));
    }

    file.close();

    return make_pair(inputs, outputs);
}

void GeneticProgram::Run()
{
    srand(1716644835);
    pair<vector<vector<double>>, vector<double>> trainingData = readData("mushroom_train.csv");
    pair<vector<vector<double>>, vector<double>> testData = readData("mushroom_test.csv");

    vector<vector<double>> trainInputs = trainingData.first;
    vector<double> trainOutputs = trainingData.second;
    vector<vector<double>> testInputs = testData.first;
    vector<double> testOutputs = testData.second;
    
    vector<Node *> population = initializePopulation(populationSize, maxDepth);

    ReplacePopulation(population, trainInputs, trainOutputs, generations, mutationRate);

    Node *bestTree = getBestTree(population, testInputs, testOutputs);

    vector<double> metrics = calculateMetrics(bestTree, testInputs, testOutputs);
    cout << "Accuracy: " << metrics[0] * 100 << "%" << endl;
    cout << "Specificity: " << metrics[1] << endl;
    cout << "Sensitivity: " << metrics[2] << endl;
    cout << "F-measure: " << metrics[3] << endl;
}

Node* GeneticProgram::getBestTree(vector<Node *> population, const vector<vector<double>> &testInputs, const vector<double> &testOutputs)
{
    Node *bestTree = population[0];
    double bestFitness = fitness(bestTree, testInputs, testOutputs);
    for (Node *tree : population)
    {
        double currentFitness = fitness(tree, testInputs, testOutputs);
        if (currentFitness < bestFitness)
        {
            bestTree = tree;
            bestFitness = currentFitness;
        }
    }

    return bestTree;
}
