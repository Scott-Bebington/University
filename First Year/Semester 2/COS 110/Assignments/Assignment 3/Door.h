#ifndef __DOOR_H__
#define __DOOR_H__


#include "Object.h"
#include <string>

using namespace std;

class Door : public Object
{
    private:
        bool open;

    public:
        Door(int x, int y, bool open);
        void interact();
        void updateLight(char direction, int intensity);
        bool unlock();

};

#endif // __DOOR_H__