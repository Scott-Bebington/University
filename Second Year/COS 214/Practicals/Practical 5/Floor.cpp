#include "Floor.h"
#include "Table.h"
void Floor::addTable(Table* table) {
    if (this->head == nullptr) {
        this->head = table;
    } else {
        Table* curr = head;
        while (curr->getNext() != nullptr) {
            curr = curr->getNext();
        }
        curr->setNext(table);
        table->setPrevious(curr);
    }
    if (table->getAvailable()) {
        this->availableTables++;
    }
}   
Table* Floor::remove(Table* table) {
    if (this->head == nullptr) {
        return nullptr;
    } else {
        if (this->head == table) {
            this->head = this->head->getNext();
            this->head->setPrevious(nullptr);
            table->setNext(nullptr);
            table->setPrevious(nullptr);
            return table;
        } else {
            Table* curr = this->head;
            while (curr->getNext() != nullptr) {
                if (curr->getNext() == table) {
                    curr->setNext(curr->getNext()->getNext());
                    curr->getNext()->setPrevious(curr);
                    table->setNext(nullptr);
                    table->setPrevious(nullptr);
                    return table;
                }
                curr = curr->getNext();
            }
        }
    }
    return nullptr;
}


Table* Floor::combine(Table* table1, Table* table2) {
    if (table1->getAvailable() && table2->getAvailable()) {
        Table* newTable = new Table(table1->getSize() + table2->getSize() - 2, true, table1->getNumber(), true, table2);
        if (this->remove(table1) == nullptr) {
            return nullptr;
        }

        if (this->remove(table2) == nullptr) {
            return nullptr;
        }
        this->addTable(newTable);
        updateAvailability();
        return newTable;
    }
    return nullptr;
}

bool Floor::split(Table* table) {
    if (table->getAvailable() && table->combined) {
        Table* newTable1 = new Table(table->getCombinedTable()->getSize(), true, table->getNumber());
        Table* newTable2 = new Table(table->getSize() - table->getCombinedTable()->getSize(), true, table->getCombinedTable()->getNumber());

        if (this->remove(table) == nullptr) {
            return false;
        }
        this->addTable(newTable1);
        this->addTable(newTable2);
        updateAvailability();
        return true;
    }
    return false;
}

void Floor::attach(Waiter* waiter, Table* table) {
    table->setWaiter(waiter);
}

void Floor::detach(Table* table) {
    table->setWaiter(nullptr);
}

Table* Floor::getFirstAvailableTable() {
    Table* curr = this->head;
    while (curr != nullptr) {
        if (curr->getAvailable()) {
            return curr;
        }
        curr = curr->getNext();
    }
    return nullptr;

}

void Floor::updateAvailability() {
    Table* curr = this->head;
    int counter = 0;
    while (curr != nullptr) {
        if (curr->getAvailable()) {
            counter++;
        }
        curr = curr->getNext();
    }
    this->availableTables = counter;
}

Table* Floor::combineTablesNumPeople(int numPeople) {
    if (this->getAvailableSeats() < numPeople) {
        return nullptr;
    }
    Table* curr = this->head;
    Table* newTable;
    int size = 0;
    while (curr != nullptr) {
        if (curr->getAvailable() && size < numPeople) {
            size += curr->getSize();
            if (newTable == nullptr) {
                newTable = curr;
            } else {
                newTable = this->combine(newTable, curr);
            }          
        }
        curr = curr->getNext();
    }
    if (size < numPeople) {
        return nullptr;
    }
    updateAvailability();

    return newTable;
}

Table* Floor::getAvailableForNumPeople(int num) {
    if (this->getAvailableSeats() < num) {
        return nullptr;
    }
    Table* curr = this->head;
    while (curr != nullptr) {
        if (curr->getAvailable() && curr->getSize() >= num) {
            return curr;
        }
        curr = curr->getNext();
    }
    return nullptr;
}

Floor::~Floor() {

}

int Floor::getAvailableSeats() {
    int counter = 0;
    Table* curr = this->head;
    while (curr != nullptr) {
        if (curr->getAvailable()) {
            counter += curr->getSize();
        }
        curr = curr->getNext();
    }

    return counter;
}

int Floor::getAvailableTables() {
    return this->availableTables;
}