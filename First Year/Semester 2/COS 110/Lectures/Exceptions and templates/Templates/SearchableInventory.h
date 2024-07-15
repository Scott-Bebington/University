#ifndef Searchable_INVENTORY_H
#define Searchable_INVENTORY_H

#include "Inventory.h"

template <typename T>
class SearchableInventory : public Inventory<T> {
	public:
		int findItem(T *);	// search for a given item
};

#endif