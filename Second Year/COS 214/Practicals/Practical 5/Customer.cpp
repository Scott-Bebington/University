using namespace std;
#include "Customer.h"
#define WHITE   "\033[37m"      /* White */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BOLDBLUE "\033[1m\033[34m"      /* Bold Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define YELLOW  "\033[33m"      /* Yellow */

Customer::Customer(int size){
	this->size = size;
	cusId = id;
}

void Customer::eat(Order* o){
    cout << "Customer " << cusId << " is eating their meal" << endl;

	srand(static_cast<unsigned int>(time(nullptr)));
    // int time = 5 + rand() % 16;
    // generate a random int between 3 and 6
    int time = 3 + rand() % 4;

	cout << "Customer " << cusId << " will eat for " << time << " seconds" << endl;
	// this_thread::sleep_for(chrono::seconds(time));               // Uncomment!!!!!

    bool payingNow = false;

    cout << "Customer is done eating" << endl;
    cout << "Would you like to pay now? (y/n)" << endl;
	string input;
	cin >> input;
	if (input == "y") 
		payingNow = true;
    
    table->getWaiter()->notify(payingNow, o);

}

int Customer::getId() {
	return cusId;
}
void Customer::enterRestaurant() {
	cout << "Customer " << cusId << " has entered the restaurant!" << endl;
	while (true){
        cout << "\n=======================\n";
        cout << "Please pick an option: \n";
        cout << RED << "0. Exit\n" << WHITE;
        cout << "1. Display menu\n";
        cout << "2. Start order\n";
        cout << "=======================\n";

        int option;
        cin >> option;
        
        switch (option)        {
        case 0:
            cout << RED << "Exiting...\n" << WHITE;
            table->setAvailable(true);
			table->getWaiter()->notifyTableAvailable();
            return;
        case 1:
            cout << "\nMenu: \n";
            this->displayMenu();
            break;
        case 2:
            table->getWaiter()->createOrder(this);
            break;
        default:
            cout << "Invalid option\n";
            break;
        }

    }
}
void Customer::displayMenu() {
    cout << GREEN << "________________________________" <<endl;
    cout << BOLDBLUE << "\nMains: \n" << WHITE;
    for (int i = 0; i < 24; i++)
    {
        cout << "|-" << i << ". " << foodBank[i].name << endl;
    }
    cout << MAGENTA << "\nDesserts: \n" << WHITE;
    for (int i = 24; i < 29; i++)
    {
        cout << "|-" << i << ". " << foodBank[i].name << endl;
    }
    cout << YELLOW << "\nDrinks: \n" << WHITE;
    for (int i = 29; i < 40; i++)
    {
        cout << "|-" << i << ". " << foodBank[i].name << endl;
    }
    cout << GREEN << "________________________________" << WHITE << endl;
}

void Customer::setTable(Table *t){
    t->setAvailable(false);
	this->table = t;
}
void Customer::setSize(int s){
	this->size = s;
}
int Customer::getSize(){
	return size;
}
Customer::~Customer(){
}
