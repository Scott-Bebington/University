#ifndef __LAMP_H__
#define __LAMP_H__


#include "Object.h"

using namespace std;

class Lamp : public Object
{
    public:
        Lamp(int x, int y);
        void update();
};

#endif // __LAMP_H__