#ifndef __RECURSIVESOLUTION_H__
#define __RECURSIVESOLUTION_H__

#include "RecursiveSolution.h"

using namespace std;
template <class T>
void solvehelper(int n, int start, int end, int aux);

template <class T>
int counthelper(stack<Disk<T> *> *Stack);

template <class T>
RecursiveSolution<T>::RecursiveSolution(int startTower, int goalTower)
{
    this->startTower = startTower;
    this->goalTower = goalTower;

    this->t1 = new stack<Disk<T> *>();
    this->t2 = new stack<Disk<T> *>();
    this->t3 = new stack<Disk<T> *>();
}

template <class T>
void solvehelper(int n, int start, int end, int aux)
{
    if (n == 0)
    {
        return;
    }
    solvehelper(n - 1, start, aux, end);
    // cout << "Move disk from tower " << start << " to tower " << end << endl;
    TowersOfHanoi<T>::moveDisk(start, end);
    solvehelper(n - 1, aux, end, start);
}

template <class T>
void RecursiveSolution<T>::solveGame()
{
    int start = this->startTower;
    int end = this->goalTower;
    int aux = 6 - (start + end);
    // int numdisks = count();
    if (TowersOfHanoi<T>::validateGame())
    {
        // solvegamehelper(1, start, end, aux);
        solvegamehelper(count(), start, end, aux);
        return;
    }
    throw Exception<T>::invalidGame();
}

template <class T>
int counthelper(stack<Disk<T> *> *Stack)
{
    if (Stack->empty())
    {
        return 0;
    }
    Disk<T> *top = Stack->top();
    Stack->pop();
    int countdisks = 1 + counthelper(Stack);
    Stack->push(top);
    return countdisks;
}

template <class T>
int RecursiveSolution<T>::count()
{
    int countdisks = 0;
    this->t1 = this->getTower(1);
    this->t2 = this->getTower(2);
    this->t3 = this->getTower(3);
    countdisks = counthelper(this->t1);
    countdisks += counthelper(this->t2);
    countdisks += counthelper(this->t3);
    return countdisks;
}

template <class T>
bool RecursiveSolution<T>::containsLabel(T label)
{
    bool flag = false;
    this->t1 = this->getTower(1);
    this->t2 = this->getTower(2);
    this->t3 = this->getTower(3);
    if (containshelp(this->t1, label))
    {
        return true;
    }
    if (containshelp(this->t2, label))
    {
        return true;
    }
    if (containshelp(this->t1, label))
    {
        return true;
    }
    return false;
}

template <class T>
bool containshelp(stack<Disk<T> *> *t, T label)
{
    if (t->empty())
    {
        return false;
    }
    if (t->top()->getLabel() == label)
    {
        return true;
    }
    t->pop();
    containshelp(t, label);
}
#endif // __RECURSIVESOLUTION_H__