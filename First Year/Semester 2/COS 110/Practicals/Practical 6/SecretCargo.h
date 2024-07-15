//The SecretCargo class

#ifndef SECRETCARGO_H
#define SECRETCARGO_H

using namespace std;

class SecretCargo
{
    private:
        double weight;
    public:
        SecretCargo(double);
        double getWeight() const;
};
#endif
