#include <iostream>

using namespace std;

int main()
{
    int x = 42; // 42 is being stored in x
    int* y = &x; // y is the memory location that x is stored in
    // "&" is the address of
    int** z = &y; // double pointer (an address of another pointer)

    cout << x << endl;
    cout << *y << endl; //*y wil return the value of x, known as dereferencing
    cout << **z << endl; //**z wil also n the value of x
    
    // "new" operator
    new int; // single variable
    new int[10]; // an array of variables

    int *p = new int; // stores the address

    // example
    int* y = new int;
    *y = 42;
    // or
    int* y;
    int x = 42;
    y = &x;
    // pointer y has the same value for both 

    // delete operation
    int *ptrvar = new int;// allocate single int
    delete ptrvar;

    int *ptrvar = new int[x]; // allocate array
    delete [] ptrvar; // delete entire array


    return 0;
}

