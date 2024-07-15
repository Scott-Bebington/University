#include <iostream>

using namespace std;

const int size = 5;

int main()
{
    //Allocation
    int*** arr2D = new int**[size];
    for(int i=0; i < size; i++)
    {
        arr2D[i] = new int*[size];
        for(int j=0; j < size; j++)
        {
            arr2D[i][j] = new int();
        }
    }

    //Deallocation
    if(arr2D != NULL)
    {
        for(int i=0; i < size; i++)
        {
            if(arr2D[i] != NULL){
                for(int j=0; j < size; j++)
                {
                    if(arr2D[i][j] != NULL)
                    {
                        delete arr2D[i][j];
                        arr2D[i][j] = NULL;
                    }
                }
                delete [] arr2D[i];
                arr2D[i] = NULL;
            }
        }
        delete [] arr2D;
        arr2D = NULL;
    }
}