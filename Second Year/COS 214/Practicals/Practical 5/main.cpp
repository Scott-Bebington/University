#include <iostream>
#include <string>
#include "HeadChef.h"
#include "CategoryChef.h"
#include "Chef.h"
#include "Waiter.h"
#include "Table.h"
#include "MaitreD.h"
#include "Floor.h"
#define WHITE   "\033[37m"      /* White */
#define RED     "\033[31m"      /* Red */
#define YELLOW  "\033[33m"      /* Yellow */

using namespace std;

// CategoryChef* populateChefs();
// Order* order = new Order();
// Employee* headChef = new HeadChef(populateChefs());
// Database* database = new Database();
// Waiter* waiter = new Waiter(database);
// Floor* theFloor = new Floor();
// MaitreD* maitreD = new MaitreD(theFloor);

// Table* table1 = new Table(3, true, 1);
// Table* table2 = new Table(3, true, 2);
// Table* table3 = new Table(3, true, 3);
// Table* table4 = new Table(3, true, 4);

// Table** table = new Table*[4] {table1, table2, table3, table4};

/// @brief this function takes in a number and calculates the fibonacci sequence up to that number
/// @param n 
/// @return The fibonacci number at the nth position
/// @author Scott Bebington
/// @date 2023-11-16
long calculate(int n) {
    if (n < 2)
        return n;
    else
        return calculate(n-1) + calculate(n-2);
}

int main() {

    cout << calculate(10) << endl;


//     for (int i = 0; i < 4; i++)
//     {
//         theFloor->addTable(table[i]);
//         maitreD->assignWaiter(waiter, table[i]);
//     }
//     Customer* customer = new Customer(6);
//     waiter->setSuccessor(headChef);
//     // waiter->setSuccessor(headChef);
//     headChef->setSuccessor(waiter);
//     cout << "=======================" << endl;
//     cout << "Available tables: " << theFloor->getAvailableTables() << endl;
//     cout << "Available seats: " << theFloor->getAvailableSeats() << endl;
//     cout << "=======================" << endl;
//     while (true)
//     {
//         cout << "Please pick an option: \n";
//         cout << RED << "0. Exit\n" << WHITE;
//         cout << "1. Make a booking\n";
//         cout << "2. Try enter restaurant\n";
        

//         int option;
//         cin >> option;
//         int size;
//         switch (option)
//         {
//         case 0:
//             cout << RED << "Exiting...\n" << WHITE;
//             return 0;
//         case 1:
//             cout << "How many people are in your party?\n";
//             cin >> size;
//             customer->setSize(size);
//             maitreD->addBooking(customer);
//             while (maitreD->checkAvailability() == false)
//             {
//                 cout << YELLOW <<"No tables available, please wait\n" << WHITE;
//             }
//             break;
//         case 2:
//             cout << "How many people are in your party?\n";
//             cin >> size;
//             customer->setSize(size);
//             maitreD->addQueue(customer);
//             while(maitreD->checkAvailability() == false)
//             {
//                 cout << YELLOW << "No tables available, please wait\n" << WHITE;
//             }
//             break;
//         default:
//             cout << RED << "!!Invalid option!!\n" << WHITE;
//             break;
//         }
//     }
    
    return 0;
}
CategoryChef* populateChefs() {
    CategoryChef *meatChef = new CategoryChef(2);
    CategoryChef *fishChef = new CategoryChef(3);
    meatChef->setNextChef(fishChef);
    CategoryChef *pizzaChef = new CategoryChef(4);
    fishChef->setNextChef(pizzaChef);
    CategoryChef *fryChef = new CategoryChef(5);
    pizzaChef->setNextChef(fryChef);
    CategoryChef *burgerChef = new CategoryChef(6);
    fryChef->setNextChef(burgerChef);
    CategoryChef *pastryChef = new CategoryChef(7);
    burgerChef->setNextChef(pastryChef);
    CategoryChef *pastaChef = new CategoryChef(8);
    pastryChef->setNextChef(pastaChef);
    CategoryChef *saladsChef = new CategoryChef(9);
    pastaChef->setNextChef(saladsChef);
    CategoryChef *drinksChef = new CategoryChef(10);
    saladsChef->setNextChef(drinksChef);
    return meatChef;
}

