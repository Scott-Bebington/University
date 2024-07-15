#include "Context.h"
#include <iostream>

using namespace std;

int main() {
    cout << endl;

    string* People = new string[3];
    People[0] = "Scott";
    People[1] = "Gary";
    People[2] = "Kyla";
    string* conditions = new string[3];
    conditions[0] = "Condition 1";
    conditions[1] = "Condition 2";
    conditions[2] = "Condition 3";

    Context* context = new Context(People, "'Contract 1'", conditions, 3, 3);

    context->castVote("Kyla", "Accepted");
    context->addCondition("Condition 4");
    
    context->castVote("Kyla", "Accepted");
    context->castVote("Scott", "Accepted");
    context->castVote("Gary", "Accepted");

    context->castVote("Kyla", "Complete");
    context->castVote("Scott", "Complete");
    context->castVote("Gary", "Complete");

    context = new Context(People, "'Contract 2'", conditions, 3, 3);
    context->castVote("Kyla", "Rejected");

    delete[] People;
    delete[] conditions;
    delete context;

    cout << endl;
    return 0;
}
