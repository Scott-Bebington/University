using namespace std;
#include "Ingredients.h"

Ingredients::Ingredients (string ingre) : Meal(){
   
    bool found = false;

    for(Food part : foodBank){
        if(part.name == ingre){
            found = true;
            this->category = part.category;
            this->name = part.name;
            this->min = part.min;
            this->max = part.max;
            this->cost = part.cost;
            break;            
        }
    }

    if(!found){
        this->category = 1;
        this->name = "Dogfood";
        this->min = 5;
        this->max = 50;
        this->cost = 250;
    }   

}

string Ingredients::getName(){
    return this->name;
}

int Ingredients::getCategory(){
    return this->category;
}

int Ingredients::getMin(){
    return this->min;
}

int Ingredients::getMax(){
    return this->max;
}

int Ingredients::getCost(){
    return this->cost;
}

void Ingredients::setNext(Meal* nextMeal){
    this->next = nextMeal;
}

void Ingredients::removeNext(){
    Meal* removing = this->next;
    this->next = removing->getNext();
}

Meal* Ingredients::getNext(){
    return this->next;
}

 Meal* Ingredients::getChild(int){
    return nullptr;
 }

 int Ingredients::getAmountIngredients(){
    return 0;
}

Meal* Ingredients::getThisMeal(){
    return nullptr;
}


Ingredients ::~Ingredients (){
}
