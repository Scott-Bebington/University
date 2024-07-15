#ifndef __WALL_H__
#define __WALL_H__


#include "Object.h"

using namespace std;
class Wall : public Object
{
    public:
        Wall(int x, int y);
        void updateLight(char direction, int intensity);
};

#endif // __WALL_H__