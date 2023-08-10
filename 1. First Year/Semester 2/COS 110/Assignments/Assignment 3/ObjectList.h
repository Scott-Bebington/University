#ifndef __OBJECTLIST_H__
#define __OBJECTLIST_H__


#include "Object.h"
#include <string>

using namespace std;

class ObjectList
{
    private:
        bool dimension;
        Object *head;
        Object* current;
    public:
        ObjectList(bool dim);
        void add(Object *obj);
        Object* getHead();
        string print();
        void reset();
        Object* iterate;
        string debug();
};
#endif 