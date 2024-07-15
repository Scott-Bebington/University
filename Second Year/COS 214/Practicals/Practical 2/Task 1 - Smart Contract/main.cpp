#include "Context.h"
#include <iostream>

using namespace std;

void Negotiation(Context* context);
void Tentatively_Accepted(Context* context);
void Accepted(Context* context);
void Rejected(Context* context);
void Completed(Context* context);

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

    Negotiation(context);
    // Tentatively_Accepted(context);
    // Accepted(context);
    // Rejected(context);
    // Completed(context);

    delete[] People;
    delete[] conditions;
    delete context;

    cout << endl;
    return 0;
}

void Negotiation(Context* context) {
    // Contract Still in the negotiation stage
    cout << context->toString() << endl;

    // Adding condition, remains in the negotiation stage
    cout << "\033[32mAdding Condition 4\033[0m" << endl<< endl;
    context->addCondition("Condition 4");
    cout << context->toString() << endl;
    
    // Removing condition, remains in the negotiation stage
    cout << "\033[31mRemoving Condition 2\033[0m" << endl<< endl;
    context->removeCondition("Condition 2");
    cout << context->toString() << endl;

    // Trying to complete the contract
    cout << "\033[38;5;208mTrying to complete the contract\033[0m" << endl;
    context->castVote("Kyla", "Complete");

    // Scott votes Accepted, move to Tentatively Accepted
    cout << endl << "\033[32mScott votes Accepted\033[0m" << endl << endl;
    context->castVote("Scott", "Accepted");
    cout << context->toString() << endl;

    // Kyla Rejects the contract, move to Rejected
    cout << endl << "\033[31mKyla Rejects the contract\033[0m" << endl << endl;
    context->castVote("Kyla", "Rejected");
    cout << context->toString() << endl;
}

void Tentatively_Accepted(Context* context) {
    // Scott votes Accepted, move to Tentatively Accepted
    cout << endl << "\033[32mScott votes Accepted\033[0m" << endl << endl;
    context->castVote("Scott", "Accepted");
    cout << context->toString() << endl;

    // Adding condition, moves back to the negotiation stage
    cout << "\033[32mAdding Condition 4\033[0m" << endl<< endl;
    context->addCondition("Condition 4");
    cout << context->toString() << endl;

    // Kyla votes Accepted, move back to Tentatively Accepted
    cout << endl << "\033[32mKyla votes Accepted\033[0m" << endl << endl;
    context->castVote("Kyla", "Accepted");
    cout << context->toString() << endl;

    // Trying to complete the contract
    cout << "\033[38;5;208mTrying to complete the contract\033[0m" << endl;
    context->castVote("Kyla", "Complete");

    // Removing condition, moves back to the negotiation stage
    cout << endl << "\033[31mRemoving Condition 2\033[0m" << endl<< endl;
    context->removeCondition("Condition 2");
    cout << context->toString() << endl;

    // All votes Accepted, move to Accepted
    cout << endl << "\033[32mAll votes Accepted\033[0m" << endl << endl;
    context->castVote("Gary", "Accepted");
    context->castVote("Scott", "Accepted");
    context->castVote("Kyla", "Accepted");
    cout << context->toString() << endl;

    // Kyla Rejects the contract, move to Rejected
    cout << endl << "\033[31mKyla Rejects the contract\033[0m" << endl << endl;
    context->castVote("Kyla", "Rejected");
    cout << context->toString() << endl;
}

void Accepted(Context* context) {
    // All votes Accepted, move to Accepted
    cout << endl << "\033[32mAll votes Accepted\033[0m" << endl << endl;
    context->castVote("Gary", "Accepted");
    context->castVote("Scott", "Accepted");
    context->castVote("Kyla", "Accepted");

    // Adding condition, should throw error message
    cout << "\033[32mAdding Condition 4\033[0m" << endl<< endl;
    context->addCondition("Condition 4");
    cout << endl << context->toString() << endl;

    // Removing condition, moves back to the negotiation stage
    cout << endl << "\033[31mRemoving Condition 2\033[0m" << endl<< endl;
    context->removeCondition("Condition 2");
    cout << endl << context->toString() << endl;

    // Casting vote to Negotiation, should throw error message
    cout << endl << "\033[38;5;208mCasting vote to Negotiation\033[0m" << endl;
    context->castVote("Gary", "Negotiation");
    cout << endl << context->toString() << endl;

    // Casting vote to Complete, Move to Complete
    cout << endl << "\033[32mCasting all votes to Complete\033[0m" << endl;
    context->castVote("Gary", "Complete");
    context->castVote("Scott", "Complete");
    context->castVote("Kyla", "Complete");
    cout << endl << context->toString() << endl;

    // Kyla Rejects the contract, move to Rejected
    cout << endl << "\033[31mKyla Rejects the contract\033[0m" << endl << endl;
    context->castVote("Kyla", "Rejected");
    cout << endl << context->toString() << endl;
}

void Rejected(Context* context) {
    // Kyla Rejects the contract, move to Rejected
    cout << endl << "\033[31mKyla Rejects the contract\033[0m" << endl << endl;
    context->castVote("Kyla", "Rejected");
    cout << endl << context->toString() << endl;

    // Casting vote to Negotiation, should throw error message
    cout << endl << "\033[38;5;208mKyla Casting vote to Negotiation\033[0m" << endl;
    context->castVote("Kyla", "Negotiation");
    cout << endl << context->toString() << endl;

    // Adding a condition
    cout << endl << "\033[32mAdding Condition 4\033[0m" << endl;
    context->addCondition("Condition 4");
    cout << endl << context->toString() << endl;
    
    // Removing a condition
    cout << endl << "\033[31mRemoving Condition 2\033[0m" << endl;
    context->removeCondition("Condition 2");
    cout << endl << context->toString() << endl;
}

void Completed(Context* context) {
    // All votes Accepted, move to Accepted
    cout << endl << "\033[32mAll votes Accepted and Completed\033[0m" << endl;
    context->castVote("Gary", "Accepted");
    context->castVote("Scott", "Accepted");
    context->castVote("Kyla", "Accepted");

    // All votes completed, move to Completed
    context->castVote("Gary", "Complete");
    context->castVote("Scott", "Complete");
    context->castVote("Kyla", "Complete");
    cout << endl << context->toString() << endl;

    // Casting vote to Negotiation, should throw error message
    cout << endl << "\033[38;5;208mCasting vote to Negotiation\033[0m" << endl;
    context->castVote("Gary", "Negotiation");
    cout << endl << context->toString() << endl;

    // Adding a condition
    cout << endl << "\033[32mAdding Condition 4\033[0m" << endl;
    context->addCondition("Condition 4");
    cout << endl << context->toString() << endl;

    // Removing a condition
    cout << endl << "\033[31mRemoving Condition 2\033[0m" << endl;
    context->removeCondition("Condition 2");
    cout << endl << context->toString() << endl;
}