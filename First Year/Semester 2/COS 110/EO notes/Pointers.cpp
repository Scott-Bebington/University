#include <iostream>

using namespace std;

int* makeArrSM(int val)
{
    int intArr[val]; // The code will seg fault as the result of makeArrSm will be NULL
    return intArr;
}

int* makeArrDM(int val)
{
    int *intArr = new int[val];
    return intArr;
}

int main()
{
    int* arrSM = makeArrSM(5);
    int* arrDM = makeArrDM(5);
    for (int i = 0; i < 5; i++)
    {
        arrSM[i] = i;
        arrDM[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "arrSM[" << i << "] :=" << arrSM[i] << endl;
        cout << "arrDM[" << i << "] :=" << arrDM[i] << endl;
    }
    delete [] arrDM;
    return 0;
}