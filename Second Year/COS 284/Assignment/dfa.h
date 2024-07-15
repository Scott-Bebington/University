#ifndef DFA_H
#define DFA_H

#include <stdbool.h>
#include <stdlib.h>

// State Structure
typedef struct
{
    int id;
    bool isAccepting;
} State;

// Transition Structure
typedef struct
{
    int from;
    int to;
    char symbol;
} Transition;

// DFA Structure
typedef struct
{
    State *states; // 8
    Transition *transitions; // 8
    int numStates; // 4
    int numTransitions; // 4
    int startState; // 4
    int fileName; // 8
} DFA;

#define MAX_ERRORS 10
typedef struct
{
    const char *errors[MAX_ERRORS];
    int numErrors;
} ErrorReport;

// Function declarations
ErrorReport *createErrorReport();
void addErrorToReport(ErrorReport *report, const char *error);
void freeErrorReport(ErrorReport *report);
DFA *readDfa(const char *filename);
// int readDfa(const char *filename); // The extern keyword is not needed in the header
void printDfa(DFA *dfa);
ErrorReport *validateDfa(DFA *dfa);
bool compareDfaWithFile(DFA *dfa, const char *filename, ErrorReport *report);
float testDeliverable1();
float testDeliverable2();
float testDeliverable3();

#endif // DFA_H
