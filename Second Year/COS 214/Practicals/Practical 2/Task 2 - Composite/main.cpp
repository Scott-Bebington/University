#include <iostream>
#include "individual.h"
#include "orgStructure.h"

using namespace std;

int main()
{
    individual *i1 = new individual(1, 10, "Scott");
    individual *i2 = new individual(2, 15, "Tim");
    individual *i3 = new individual(10, 20, "Kyla");
	individual *i4 = new individual(100, 150, "Stefan");

    orgStructure *o1 = new orgStructure();
    o1->addIndividual(i1);
    o1->addIndividual(i2);

    cout << "\033[38;5;208mCost Center 1\033[0m" << endl;
    o1->print();
    cout << "\033[32mTotal cost to center: R" << o1->getExpenditureByCostCenter() << "\033[0m" << endl << endl;

    orgStructure o2;
    o2.addIndividual(i3);
	o2.addIndividual(i4);

    cout << "\033[38;5;208mCost Center 2\033[0m" << endl;
    o2.print();
    cout << "\033[32mTotal cost to center: R" << o2.getExpenditureByCostCenter() << "\033[0m" << endl << endl;

    cout << "\033[38;5;208mAll Cost Centers\033[0m" << endl;
    cout << "\033[32mTotal cost to company: R" << o2.getTotalExpenditure() << "\033[0m" << endl << endl;

    delete i1;
    delete i2;
    delete i3;
    delete o1;

    return 0;
}
