#include "Operator.h"
#include <iostream>

Operator::Operator(int val)
{
    this->val = val;
}

Operator::~Operator()
{
    
}

int Operator::getVal()
{
    return val;
}

Operator& Operator::operator=(const Operator& other)
{
    Operator* op = new Operator(other.val);
    return *op;
}

int main(){ //never do this in your practicals
    Operator op1(5);
    std::cout << &op1 << ":" << op1.getVal() << std::endl;
    Operator op2 = op1;
    std::cout << &op1 << ":" << op1.getVal() << std::endl;
    std::cout << &op2 << ":" << op2.getVal() << std::endl;
}

/*
0x7ffffffedfec:5
0x7ffffffedfec:5
0x7ffffffedfe8:5
*/