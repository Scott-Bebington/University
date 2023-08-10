#ifndef TOH_H
#define TOH_H

#include <stack>

#include "Exception.h"
#include "Disk.h"

using namespace std;

template <class T>
class TowersOfHanoi
{
    protected:
        std::stack<Disk<T>*>* t1;
        std::stack<Disk<T>*>* t2;
        std::stack<Disk<T>*>* t3;

        int startTower;
        int goalTower;

        TowersOfHanoi();

    public:
        void moveDisk(int dep, int dest);
        TowersOfHanoi(int startTower, int goalTower);
        void addDisk(T diskData, int tower);
        bool validateGame();
        stack<Disk<T>*>* getTower(int tower);
        ~TowersOfHanoi();
        virtual void solveGame() = 0;
};

#endif