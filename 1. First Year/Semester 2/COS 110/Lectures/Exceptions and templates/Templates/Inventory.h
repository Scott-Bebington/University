#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Inventory {
 public:
	  Inventory(int = 10);
	  virtual ~Inventory();

	  T * inspectItem(int i);
	  T * getLastItem();
	  void addItem(T * );
 
	  int getNumItems() const;
	  bool isEmpty() const;
 
 protected:
	  T* * inventory;
	  int size;
	  int numItems;
};

#endif
