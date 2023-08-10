#ifndef ROCKET4_H
#define ROCKET4_H

#include <string>
class Pilot{};//this would be defined in another file

class Rocket4{
    private:
        std::string name;
        Pilot** crew;
        int crewSize;
    protected:
        double fuelRemaining;
        double distanceRemaining;
    public:
        Rocket4(std::string name, int crewSize);
        Rocket4(Rocket4* rocket);
        int addToCrew(Pilot* crewMember);
        void printRocketInfo();
        void setFuel(double fuel);
        void setDistance(double distance);
        double getDistance() const;
        double getFule() const;
        ~Rocket4();
};

#endif