#include <iostream>

using namespace std;

struct Number{
};
const int size = 5;

int main(){
    //Allocation
    Number**** arr3D = new Number***[size];
    for(int i=0; i < size; i++){
        arr3D[i] = new Number**[size];
        for(int j=0; j < size; j++){
            arr3D[i][j] = new Number*[size];
            for(int k=0; k < size; k++){
                arr3D[i][j][k] = new Number();
            }
        }
    }

    //Deallocation
    if(arr3D != NULL){
        for(int i=0; i < size; i++){
            if(arr3D[i] != NULL){
                for(int j=0; j < size; j++){
                    if(arr3D[i][j] != NULL){
                        for(int k=0; k < size; k++){
                            if(arr3D[i][j][k] != NULL){
                               delete arr3D[i][j][k]; 
                               arr3D[i][j][k] = NULL;
                            }
                        }
                        delete [] arr3D[i][j];
                        arr3D[i][j] = NULL;
                    }
                }
                delete [] arr3D[i];
                arr3D[i] = NULL;
            }
        }
        delete [] arr3D;
        arr3D = NULL;
    }
}