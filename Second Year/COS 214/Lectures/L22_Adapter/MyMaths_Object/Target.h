#ifndef TARGET_H
#define TARGET_H

class Target {
public:
    virtual int operator+(int) = 0;
    virtual int operator*(int) = 0;
    virtual int operator=(int) = 0;
};

#endif
