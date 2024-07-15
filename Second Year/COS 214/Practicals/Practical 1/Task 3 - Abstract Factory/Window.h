#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>

using namespace std;

class Window
{

protected:

    string toString();

public:

    int screenHeight;
    int screenWidth;
    int primitiveCount;
    int primitiveCapacity;

    int getScreenHeight();
    int getScreenWidth();
    int getPrimitiveCount();
    int getPrimitiveCapacity();

    void setScreenHeight(int screenHeight);
    void setScreenWidth(int screenWidth);
    void setPrimitiveCount(int primitiveCount);
    void setPrimitiveCapacity(int primitiveCapacity);
    

};

#endif // WINDOW_H