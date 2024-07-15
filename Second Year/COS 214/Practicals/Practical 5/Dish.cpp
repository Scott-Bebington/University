
using namespace std;
#include "Dish.h"


Dish::Dish (string dis) : Meal(){
       
    bool found = false;

    for(Food part : foodBank){
        if(part.name == dis){
            found = true;
            this->category = part.category;
            this->name = part.name;
            this->min = part.min;
            this->max = part.max;
            this->cost = part.cost;
            this->amountIngredients = part.size;
            this->thisMeal = new Meal[part.size];

            for(int i = 0; i < part.size;i++){
                this->thisMeal[i] =  Ingredients(part.ingredients[i]);
            }


            break;            
        }
    }   


    if(!found){
        this->category = 1;
        this->name = "Dogfood";
        this->min = 5;
        this->max = 50;
        this->cost = 250;
        this->thisMeal = NULL;
    }   

}

string Dish::getName(){
    return this->name;
}

int Dish::getCategory(){
    return this->category;
}

int Dish::getMin(){
    return this->min;
}

int Dish::getMax(){
    return this->max;
}

int Dish::getCost(){
    return this->cost;
}

int Dish::getAmountIngredients(){
    return this->amountIngredients;
}

Meal* Dish::getThisMeal(){
    return this->thisMeal;
}

void Dish::setNext(Meal* nextMeal){
    this->next = nextMeal;
}

void Dish::removeNext(){
    Meal* removing = this->next;
    this->next = removing->getNext();
}

Meal* Dish::getNext(){
    // cout << "Dish's getNext() called" << endl;
    return this->next;
}


Meal* Dish::getMeal(){
    return this;
}



// void Dish::addIngredient(Meal* m){
    
//     Meal* newIngre = new Meal[this->amountIngredients+1];
//     for(int i = 0; i < this->amountIngredients; i++){
//         newIngre[i] = this->thisMeal[i];
//     }
//     newIngre[this->amountIngredients] = *m;
//     this->amountIngredients++;
//     this->thisMeal = newIngre;

// }
// void Dish::removeIngredient(Meal* m){

//     Meal* newIngre = new Meal[this->amountIngredients-1];
//     int j = 0;
//     for(int i = 0; i < this->amountIngredients; i++){

//         if(this->thisMeal[i].getName() != m->getName()){  
//             newIngre[j] = this->thisMeal[i];
//             j++;
//         }
//     }
//     this->amountIngredients--;
//     this->thisMeal = newIngre;

// }

Meal* Dish::getChild(int child){
    return &this->thisMeal[child];
}
Dish::~Dish(){
    delete[] this->thisMeal;
}