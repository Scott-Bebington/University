#ifndef __TOWERSOFHANOI_H__
#define __TOWERSOFHANOI_H__

#include "TowersOfHanoi.h"
#include <stack>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T>
TowersOfHanoi<T>::TowersOfHanoi()
{
}

template <class T>
void TowersOfHanoi<T>::moveDisk(int dep, int dest)
{
    // cout << "Start pole: " << dep << endl;
    // cout << "End pole  : " << dest << endl;
    if (dep < 1 || dep > 3 || dest < 1 || dest > 3)
    {
        throw Exception<T>::incorrectDiskMove(dep, dest);
    }
    std::stack<Disk<T> *> *start = NULL;
    std::stack<Disk<T> *> *end = NULL;
    switch (dep)
    {
    case 1:
        start = t1;
        break;
    case 2:
        start = t2;
        break;
    case 3:
        start = t3;
        break;
    }
    switch (dest)
    {
    case 1:
        end = t1;
        break;
    case 2:
        end = t2;
        break;
    case 3:
        end = t3;
        break;
    }
    // cout << "Test 5" << endl;
    if (start == end)
    {
        throw Exception<T>::incorrectDiskMove(dep, dest);
    }
    // cout << "Test 6" << endl;
    if ((start->empty() && end->empty()))
    {
        throw Exception<T>::emptyStack(dep);
    }
    // cout << "Test 7" << endl;
    if (start->empty())
    {
        // cout << "start is empty" << endl;
        Disk<T> *temp = end->top();
        end->pop();
        start->push(temp);
        Exception<T>::movePlan(temp, dest, dep);
        return;
    }
    // cout << "Test 8" << endl;
    if (end->empty())
    {
        Disk<T> *temp = start->top();
        start->pop();
        end->push(temp);
        Exception<T>::movePlan(temp, dep, dest);
        return;
    }
    if (start->top()->getLabel() > end->top()->getLabel())
    {
        // cout << "Test 9" << endl;
        Disk<T>* temp = end->top();
        end->pop();
        start->push(temp);
        Exception<T>::movePlan(temp, dest, dep);
        return;
    }
    // cout << "Test" << endl;
    Disk<T> *temp = start->top();
    start->pop();
    end->push(temp);
    Exception<T>::movePlan(temp, dep, dest);
}

template <class T>
TowersOfHanoi<T>::TowersOfHanoi(int startTower, int goalTower)
{
    startTower = startTower;
    goalTower = goalTower;

    t1 = new stack<Disk<T> *>();
    t2 = new stack<Disk<T> *>();
    t3 = new stack<Disk<T> *>();
}

template <class T>
void TowersOfHanoi<T>::addDisk(T diskData, int tower)
{
    if (tower < 1 || tower > 3)
    {
        throw Exception<T>::invalidDiskAdd(tower, diskData);
    }
    if (tower == 1)
    {
        if (t1->empty())
        {
            t1->push(new Disk<T>(diskData));
            return;
        }
        Disk<T> *currentdisk = t1->top();
        int current = currentdisk->getLabel();
        if (diskData > current)
        {
            throw Exception<T>::invalidTower(tower);
        }
        t1->push(new Disk<T>(diskData));
        return;
    }
    if (tower == 2)
    {
        if (t2->empty())
        {
            t2->push(new Disk<T>(diskData));
            return;
        }
        Disk<T> *currentdisk = t2->top();
        int current = currentdisk->getLabel();
        if (diskData > current)
        {
            throw Exception<T>::invalidTower(tower);
        }
        t2->push(new Disk<T>(diskData));
        return;
    }
    if (tower == 3)
    {
        if (t3->empty())
        {
            t3->push(new Disk<T>(diskData));
            return;
        }
        Disk<T> *currentdisk = t3->top();
        int current = currentdisk->getLabel();
        if (diskData > current)
        {
            throw Exception<T>::invalidTower(tower);
        }
        t3->push(new Disk<T>(diskData));
        return;
    }
}

template <class T>
bool TowersOfHanoi<T>::validateGame()
{
    int count = 0;
    if (!t1->empty())
    {
        count++;
    }
    if (!t2->empty())
    {
        count++;
    }
    if (!t3->empty())
    {
        count++;
    }
    if (count != 1)
    {
        return false;
    }
    return true;
}

template <class T>
TowersOfHanoi<T>::~TowersOfHanoi()
{
    delete t1;
    delete t2;
    delete t3;
}

template <class T>
stack<Disk<T> *> *TowersOfHanoi<T>::getTower(int tower) // works
{
    if (tower == 1)
    {
        return t1;
    }
    if (tower == 2)
    {
        return t2;
    }
    if (tower == 3)
    {
        return t3;
    }
}

#endif // __TOWERSOFHANOI_H__
