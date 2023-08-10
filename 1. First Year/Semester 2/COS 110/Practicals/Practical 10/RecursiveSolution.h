#ifndef RS_H
#define RS_H

#include <stack>

#include "TowersOfHanoi.h"
#include "Disk.h"

template <class T>
class RecursiveSolution : public TowersOfHanoi<T>
{
    public:
        RecursiveSolution(int startTower, int goalTower);
        void solveGame();
        int count();
        bool containsLabel(T label);
};

#endif