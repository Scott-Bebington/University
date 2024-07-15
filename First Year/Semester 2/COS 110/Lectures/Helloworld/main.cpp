#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec(3);
    vec.push_back(9);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ",";
    }
    cout << endl;

    vec.erase(vec.begin() + 1);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ",";
    }
    cout << endl;

    vec.insert(vec.begin(), 7);
    vec.insert(vec.begin() + 1, 1);
    vec.insert(vec.end(), 8);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ",";
    }
    cout << endl;

    vec.erase(vec.begin() + 3, vec.end()-1);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ",";
    }
    cout << endl;

    vec.insert(vec.end(), vec.begin(), vec.begin() + 2);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ",";
    }
    cout << endl;   
}