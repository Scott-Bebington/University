// MyMaths.h
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

// MyMaths.cpp
#include "MyMaths.h"

template <typename T>
MyMaths<T>::MyMaths(T v1, T v2){
    x = v1;
    y = v2;
}

template <typename T>
T MyMaths<T>::add() {
    return x + y;
}

template <typename T>
T MyMaths<T>::multiply() {
    return x * y;
}

template <typename T>
void MyMaths<T>::setX(T object){
    x = object;
}

template <typename T>
void MyMaths<T>::setY(T object){
    y = object;
}

#ifndef TARGET_H
#define TARGET_H

class Target {
public:
    virtual int operator+(int) = 0;
    virtual int operator*(int) = 0;
    virtual int operator=(int) = 0;
};
#endif

// NewMaths.h
#ifndef NEWMATHS_H
#define NEWMATHS_H

#include "Target.h"
#include "MyMaths.h"

class NewMaths : public Target{
public:
    NewMaths();
    NewMaths(int);
    virtual int operator+(int);
    virtual int operator*(int);
    virtual int operator=(int);
    ~NewMaths();
private:
    MyMaths<int>* adaptee;
};
#endif

// NewMaths.cpp
#include <iostream>

#include "MyMaths.h"
#include "NewMaths.h"

using namespace std;

NewMaths::NewMaths(){
    adaptee = new MyMaths<int>(0,0);
}

NewMaths::NewMaths(int v){
    adaptee = new MyMaths<int>(v,0);
}

int NewMaths::operator+(int i){
    adaptee->setY(i);
    return adaptee->add();
}

int NewMaths::operator*(int){
// Impementation needed    
}

int NewMaths::operator=(int v){
    adaptee->setX(v);
    return v;
}

NewMaths::~NewMaths(){
    delete adaptee;
}

