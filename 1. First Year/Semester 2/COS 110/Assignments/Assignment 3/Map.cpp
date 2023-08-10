#ifndef __MAP_CPP__
#define __MAP_CPP__

#include "Map.h"

using namespace std;

Map::Map(int w, int h)
{
    width = w;
    height = h;

    rows = new ObjectList*[width];
    columns = new ObjectList*[height];
}

void Map::add(Object* obj)
{
    int verticalPos = obj->getCoord(true);
    int horizontalPos = obj->getCoord(false);
    rows[horizontalPos]->add(obj);
    columns[verticalPos]->add(obj);
}

string Map::print()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            
        }
    }
}

#endif // __MAP_H__