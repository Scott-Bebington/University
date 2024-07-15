#include "MaitreD.h"

MaitreD::MaitreD(Floor* f) {
    this->floor = f;
}
MaitreD::~MaitreD() {
    
}

Table* MaitreD::seat(Customer* c) {
    if (floor->getFirstAvailableTable() == nullptr) {
        return nullptr;
    } else {
        Table* t = floor->getFirstAvailableTable();
        c->setTable(t);
        return t;
    }
    return nullptr;
}
void MaitreD::addBooking(Customer* c) {
    this->bookings.push(c);
}
void MaitreD::addQueue(Customer* c) {
    this->queue.push(c);
}
bool MaitreD::checkAvailability() {
    if (floor->getFirstAvailableTable() != nullptr)
    {
        notify();
        return true;
    }
    return false;
}
bool MaitreD::removeBooking(Customer* c) {
    std::queue<Customer*> tempQueue;
    while (!bookings.empty()) {
        if (bookings.front() == c) {
            bookings.pop();
            return true;
        } else {
            tempQueue.push(bookings.front());
            bookings.pop();
        }
    }
    bookings = tempQueue;
    return false;
}

bool MaitreD::combine(Table* t1, Table* t2) {
    return floor->combine(t1, t2);
}
bool MaitreD::split(Table* t) {
    return floor->split(t);
}
void MaitreD::assignWaiter(Waiter* w, Table* t) {
    t->setWaiter(w);
}
void MaitreD::notify() {
    Table* openTable = floor->getFirstAvailableTable();
    if (bookings.front()) {
        cout << "No bookings" << endl;
        Customer* c = bookings.front();
        if (openTable != nullptr && c->getSize() < openTable->getSize()) {
            c->setTable(openTable);
            bookings.pop();
            floor->updateAvailability();
            c->enterRestaurant();
        } else if (floor->getAvailableForNumPeople(c->getSize()) != nullptr) {
            Table* t = floor->getAvailableForNumPeople(c->getSize());
            c->setTable(t);
            bookings.pop();
            floor->updateAvailability();
            c->enterRestaurant();
        } else {
            Table* t = floor->combineTablesNumPeople(c->getSize());
            if (t != nullptr) {
                c->setTable(t);
                bookings.pop();
                floor->updateAvailability();
                c->enterRestaurant();
            } else {
                std::cout << "No tables available" << std::endl;
            }
        }
    } else if (!queue.empty()) {
        Customer* c = queue.front();
        if (openTable != nullptr && c->getSize() < openTable->getSize()) {
            c->setTable(openTable);
            bookings.pop();
            floor->updateAvailability();
            c->enterRestaurant();
        } else if (floor->getAvailableForNumPeople(c->getSize()) != nullptr) {
            Table* t = floor->getAvailableForNumPeople(c->getSize());
            c->setTable(t);
            bookings.pop();
            floor->updateAvailability();
            c->enterRestaurant();
        } else {
            Table* t = floor->combineTablesNumPeople(c->getSize());
            if (t != nullptr) {
                c->setTable(t);
                bookings.pop();
                floor->updateAvailability();
                c->enterRestaurant();
            } else {
                std::cout << "No tables available" << std::endl;
            }
        }
    } else {
        std::cout << "No customers waiting" << std::endl;
    }
    floor->updateAvailability();
    
}