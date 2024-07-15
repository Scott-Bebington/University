//abstract base class

#ifndef POLYGON_H
#define  POLYGON_H

#include <iostream>
using namespace std;

class Polygon {

  public:
    void set_values (int a, int b);
    virtual int area() =0;   //Pure virtual function
    
      
 protected:
    int width;
    int height;
};

#endif