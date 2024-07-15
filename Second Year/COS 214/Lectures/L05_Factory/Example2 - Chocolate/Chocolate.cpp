#include <iostream>
#include "Chocolate.h"

using namespace std;


int Chocolate::total_ = 0;

Chocolate::Chocolate() {
      id_ = total_++;
}

void Chocolate::wrap() {
  print();
  cout << " " << id_ << ":wrap" << endl;
}

void Chocolate::print() {
  cout<<"Please implement this function in subclasses"<<endl;
}

void Barone::print() { 
  cout << "Barone"; 
}


void Tex::print() {
   cout << "Tex"; 
}


Chocolate* Creator::produce() {
  cout<<"Producing chocolate";
  return produceProduct();
}


Chocolate* BaroneCreator::produceProduct() {
  cout<<"--->>Barone"<<endl;
  return new Barone();
}


Chocolate* TexCreator::produceProduct() {
  cout<<"--->>Tex"<<endl;
  return new Tex();
}
