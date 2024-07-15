#ifndef __PLAYER_H__
#define __PLAYER_H__


#include "Object.h"

using namespace std;

class Player : public Object
{
    public:
        Player(int x, int y);
        void move(int x, int y);

};
#endif // __PLAYER_H__