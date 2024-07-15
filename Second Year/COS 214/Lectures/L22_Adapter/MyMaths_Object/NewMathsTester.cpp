#include <iostream>


#include "Target.h"
#include "NewMaths.h"

using namespace std;

int main()
{
    Target* obj = new NewMaths(4);
    
    int temp;
    temp  = (*obj +3);
    cout << temp << endl;  
    
    *obj = 10;
    temp  = (*obj + 3);
    cout << temp << endl;  

    
    return 0;
}