#ifndef ARTEFACT_H
#define ARTEFACT_H
#include <iostream>
#include <string>
using namespace std;

enum Material { STONE = 1, COPPER = 2, SILVER = 3, GOLD = 4};

class Artefact {
 public:

  Artefact(string d, Material m, int a, int v = -1);
  ~Artefact();

  string getDescription() const;
  int getAge() const;
  int getValue() const;
  Material getMaterial() const;
  void setValue(int);
  bool operator< (Artefact&);
  
 private:
  int value;
  int age;
  Material material;
  string description;
};

#endif
