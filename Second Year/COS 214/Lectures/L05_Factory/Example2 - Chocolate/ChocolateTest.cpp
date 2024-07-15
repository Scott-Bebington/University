#include <iostream>
#include "Chocolate.h"

using namespace std;

int main(){
    Creator* factory[2];
    factory[0] = new BaroneCreator();
    factory[1] = new TexCreator();
    Chocolate* storage[6];
    for (int i = 0; i < 6; i++) 
        storage[i] = factory[i%2]->produce();
     
    for (int i = 0; i < 6; i++)
       storage[i]->wrap();

    // delete all memory    
    for (int i = 0; i < 6; i++)
       delete storage[i];
    for (int i = 0; i < 2; i++)
       delete factory[i];
    
    return 0;
}

 
