#include "SearchableInventory.h"

template <typename T>
int SearchableInventory<T>::findItem(T * item)
{
	for(int i = 0; i < this->numItems; i++) {
		
		if(item == this->inventory[i])
			return i;
	}
	
	throw "Item not found";
}