#include <iostream>
#include <string>

#include "Exception.h"
#include "Disk.cpp"
#include "TowersOfHanoi.cpp"
#include "IterativeSolution.cpp"
#include "RecursiveSolution.cpp"

using namespace std;

// template <class T>
// void printStack(stack<Disk<T> *> *s)
// {
//     // If stack is empty then return
//     if (s->empty())
//         return;

//     Disk<T> *x = s->top();

//     // Pop the top element of the stack
//     s->pop();

//     // Recursively call the function PrintStack
//     printStack(s);

//     // Print the stack element starting
//     // from the bottom
//     cout << x->getLabel() << "\n";

//     // Push the same element onto the stack
//     // to preserve the order
//     s->push(x);
// }

// int main()
// {

//     cout << "Let's create a new game, shall we?" << endl;
//     TowersOfHanoi<int> *gameOne = new IterativeSolution<int>(1, 3);
//     cout << "Adding disks" << endl;
//     gameOne->addDisk(3, 1);
//     gameOne->addDisk(2, 1);
//     gameOne->addDisk(1, 1);
//     gameOne->addDisk(0, 1);

//     cout << "Is the game valid?" << endl;
//     if (gameOne->validateGame())
//     {
//         cout << "   Yeah, it is valid" << endl << endl;
//     } 
//     else
//     {
//         cout << "   Nope. The game is not valid" << endl << endl;
//     }
//     cout << "Let me add just one more disk" << endl;
//     try
//     {
//         gameOne->addDisk(4, 1);
//     }
//     catch (Exception<int> *e)
//     {
//         cout << e->message << endl << endl;
//     }

//     cout << "Printing disks in the game" << endl;
//     for (int i = 1; i <= 3; i++)
//     {
//         cout << "Tower " << i << endl;
//         printStack(gameOne->getTower(i));
//     }
//     cout << endl;

//     cout << "SOLVE GAME: " << endl;
//     try
//     {
//         gameOne->solveGame();
//     }
//     catch (Exception<int> *e)
//     {
//         cout << e->message << endl;
//     }
//     cout << endl;

//     cout << "Printing disks in the game" << endl;
//     for (int i = 1; i <= 3; i++)
//     {
//         cout << "Tower " << i << endl;
//         printStack(gameOne->getTower(i));
//     }
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include <string>

#include "Exception.h"
#include "Disk.cpp"
#include "TowersOfHanoi.cpp"
#include "IterativeSolution.cpp"
#include "RecursiveSolution.cpp"

using namespace std;

int main()
{
    IterativeSolution<int>* game1 = new IterativeSolution<int>(1,3);
    // game1->addDisk(6, 1);
    // game1->addDisk(5, 1);
    // game1->addDisk(4, 1);
    // game1->addDisk(3, 1);
    game1->addDisk(2, 1);
    game1->addDisk(1, 1);
    game1->addDisk(0, 1);

    try
    {
        game1->solveGame();
        // game1->moves(3);
    }
    catch(Exception<int>* exe)
    {
        cout << exe->message << endl;
    }

    // RecursiveSolution<int>* game2 = new RecursiveSolution<int>(1,3);
    // // game2->addDisk(6, 1);
    // // game2->addDisk(5, 1);
    // game2->addDisk(4, 1);
    // game2->addDisk(3, 1);
    // game2->addDisk(2, 1);
    // game2->addDisk(1, 1);
    // game2->addDisk(0, 1);

    // // cout << "Game 2 contains " << game2->count() << " disks" << endl;
    // // if (game2->containsLabel(5))
    // // {
    // //     cout << "Game 2 contains the label 2" << endl;
    // // }
    // // else
    // // {
    // //     cout << "Game 2 does not contain the label 5" << endl;
    // // }
    // try
    // {
    //     game2->solveGame();
    // }
    // catch(Exception<int>* exe)
    // {
    //     cout << exe->message << endl;
    // }

    return 0;
}