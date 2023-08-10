//File for all exception definitions
//See spec for inclusion strategy
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <sstream>

using namespace std;

class AboveWeightEx
{
    private:
        double weightDiff;
    public:
        AboveWeightEx(double);
        double getDifference() const;
};

class EmptyEx
{
    EmptyEx();
};

class UnauthorisedEx
{
    UnauthorisedEx();
};
template <typename E>
class UndervaluedEx
{
    private:
        E* underVal;
        double sum;
    public:
        UndervaluedEx(E*, double);
        E* getUndervalued() const;
        double getSum() const;
};
template <typename E>
class NotFoundEx
{
    private:
        E missing;
    public:
        NotFoundEx(E*);
        E* getNotFound() const;
};
#endif