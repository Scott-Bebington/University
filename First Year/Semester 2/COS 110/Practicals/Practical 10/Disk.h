#ifndef DISK_H
#define DISK_H

using namespace std;

template <class T>
class Disk
{
    private:
        T label;

    public:
        Disk(T label);
        const T getLabel();
};

#endif