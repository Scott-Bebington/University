#ifndef __ITERATIVESOLUTION_H__
#define __ITERATIVESOLUTION_H__

#include "IterativeSolution.h"

using namespace std;

template <class T>
IterativeSolution<T>::IterativeSolution(int startTower, int goalTower)
{
    this->startTower = startTower;
    this->goalTower = goalTower;

    this->t1 = new stack<Disk<T> *>();
    this->t2 = new stack<Disk<T> *>();
    this->t3 = new stack<Disk<T> *>();
}

template <class T>
void IterativeSolution<T>::solveGame()
{
    if (TowersOfHanoi<T>::validateGame())
    {
        int start = this->startTower;
        stack<Disk<T> *> *tower1 = TowersOfHanoi<T>::getTower(start);

        int minmoves = pow(2, tower1->size()) - 1; // 7
        moves(minmoves);
        return;
    }
    throw Exception<T>::invalidGame();
}

template <class T>
void IterativeSolution<T>::moves(int numMoves)
{
    // cout << "Test 1" << endl;
    int start = this->startTower;
    int end = this->goalTower;
    int aux = 6 - (start + end);

    stack<Disk<T> *> *tower1 = TowersOfHanoi<T>::getTower(start);
    int minmoves = numMoves;
    if (tower1->size() % 2 == 0)
    {
        int temp = end;
        end = aux;
        aux = temp;
    }
    // cout << "Test 2" << endl;
    try
    {
        // cout << "Test 3" << endl;
        for (int i = 1; i <= minmoves; i++)
        {
            // cout << "Test 4" << endl;
            if (i % 3 == 1)
            {
                // cout << "case 1 start" << endl;
                TowersOfHanoi<T>::moveDisk(start, end);
                // cout << "case 1 end" << endl;
                continue;
            }
            if (i % 3 == 2)
            {
                // cout << "case 2" << endl;
                TowersOfHanoi<T>::moveDisk(start, aux);
                continue;
            }
            if (i % 3 == 0)
            {
                // cout << "case 3" << endl;
                TowersOfHanoi<T>::moveDisk(aux, end);
                continue;
            }
        }
    }
    catch (Exception<T> *exe)
    {
        cout << exe->message << endl;
    }
}

#endif // __ITERATIVESOLUTION_H__

// 4 disks

// 0 was moved from 1 to 2
// 1 was moved from 1 to 3
// 0 was moved from 2 to 3

// 2 was moved from 1 to 2
// 0 was moved from 3 to 1
// 1 was moved from 3 to 2

// 0 was moved from 1 to 2
// 1 was moved from 1 to 3
// 0 was moved from 2 to 3

// 0 was moved from 2 to 1
// 0 was moved from 3 to 1
// 0 was moved from 2 to 3

// 0 was moved from 1 to 2
// 0 was moved from 1 to 3
// 0 was moved from 2 to 3
