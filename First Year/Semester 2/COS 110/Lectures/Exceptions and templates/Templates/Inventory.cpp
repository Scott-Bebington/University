#include "Inventory.h"
#include "Artefact.h"

template <typename T>
Inventory<T>::Inventory(int s)
{
  size = s;
  inventory = new T * [s];  
  numItems = 0;
}

template <typename T>
Inventory<T>::~Inventory()
{
  for(int i = 0; i < numItems; i++)
    delete inventory[ i ];

  delete [] inventory;
}

template <typename T>
T * Inventory<T>::inspectItem(int i)
{
  if (i < numItems && i >= 0)
    return inventory[i];
  else {
    cout << "Invalid index" << endl;
    return NULL;
  }
}

template <typename T>
T * Inventory<T>::getLastItem()
{
  if(!isEmpty()) {
    T * item = inventory[numItems - 1];
    inventory[numItems--] = 0;
    return item; 
  } else {
    cout << "Inventory is empty" << endl;
    return NULL;
  }
}

template <typename T>
void Inventory<T>::addItem(T* item)
{
  if(numItems == size) 
  { 
    size *= 2;
    T ** temp = new T*[size];
    for(int i = 0; i < numItems; i++) 
    {
      temp[i] = inventory[i];
    }
    delete [] inventory;
    inventory = temp;
  }

  inventory[numItems++] = item;
}

template <typename T>
bool Inventory<T>::isEmpty() const
{
  if(numItems > 0) return false;
  else return true;
}

template <typename T>
int Inventory<T>::getNumItems() const
{
  return numItems;
}
