#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

void readValuesFromTextFile(string filename, vector<vector<float>> &weightValueVector, int &knapsackWeightLimit, int &numberOfItems)
{
    // Open the file
    ifstream file(filename);

    // Check if the file is open
    if (!file.is_open())
    {
        cout << "Error: File not found" << endl;
        return;
    }

    // Read the file line by line
    string line;
    getline(file, line);
    stringstream ss(line);
    ss >> numberOfItems >> knapsackWeightLimit;

    while (getline(file, line))
    {
        stringstream ss(line);
        float weight, value;
        ss >> value >> weight;
        float WeightValueRatio = value / weight;
        weightValueVector.push_back({value, weight, WeightValueRatio, false});
    }

    // Close the file
    file.close();
}

void printVector(vector<vector<float>> &weightValueVector)
{
    for (const auto &pair : weightValueVector)
    {
        cout << "Value: " << pair[0] << "\tWight: " << pair[1] << " \tWeight/Value: " << pair[2] << "\tItem in bag: " << pair[3] << endl;
    }
}

void initialSelection(vector<vector<float>> &weightValueVector, vector<bool> &selectedItems, int knapsackWeightLimit)
{
    float totalWeight = 0;
    float totalValue = 0;
    for (int i = 0; i < weightValueVector.size(); i++)
    {
        if (totalWeight + weightValueVector[i][1] <= knapsackWeightLimit)
        {
            totalWeight += weightValueVector[i][1];
            totalValue += weightValueVector[i][0];
            weightValueVector[i][3] = true;
            selectedItems.push_back(true);
        }
        else
        {
            selectedItems.push_back(false);
        }
    }

    cout << "Total weight: " << totalWeight << endl;
    cout << "Total value: " << totalValue << endl;
    cout << "Selected items: " << endl;
    printVector(weightValueVector);
}

int crossoverPoint(vector<bool> &selectedItems)
{
    if (selectedItems.empty()) {
        return -1; // or any other appropriate value to indicate an error
    }

    int crossoverPoint = rand() % selectedItems.size();
    return crossoverPoint;
}

int main()
{
    unsigned int seed = 42;
    srand(seed);

    int knapsackWeightLimit = 0;
    int numberOfItems = 0;
    vector<vector<float>> weightValueVector;
    vector<bool> selectedItems;
    readValuesFromTextFile("f1_l-d_kp_10_269", weightValueVector, knapsackWeightLimit, numberOfItems);
    initialSelection(weightValueVector, selectedItems, knapsackWeightLimit);

    cout << "Cross over point: " << crossoverPoint(selectedItems) << endl;

    return 0;
}
