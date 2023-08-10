#ifndef __MAP_H__
#define __MAP_H__


#include "ObjectList.h"
#include <string>

using namespace std;
class Map
{
    private:
        int width;
        int height;
        ObjectList** rows;
        ObjectList** columns;
        ObjectList* lights;
    
    public:
        Map(int w, int h);
        void add(Object* obj);
        string print();
        void addLight(Object* l);
        Object* getAt(int x, int y);
        void resetEnvironment();
        void updateEnvironment();
        ~Map();
};

#endif // __MAP_H__