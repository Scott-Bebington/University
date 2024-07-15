#ifndef MYMATHS_H
#define MYMATHS_H

template <typename T>
class MyMaths {
public:
    MyMaths(T, T);
    T add ();
    T multiply();

 //protected: 
    void setX(T);
    void setY(T);
    
  private:
    T x;
    T y;
};

#include "MyMaths.cpp"

#endif

    

