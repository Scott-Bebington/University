#ifndef OPERATOR_H
#define OPERATOR_H

class Operator{
    private:
        int val;

    public:
        Operator(int val);
        ~Operator();
        int getVal();
        Operator& operator=(const Operator& other);
};

#endif