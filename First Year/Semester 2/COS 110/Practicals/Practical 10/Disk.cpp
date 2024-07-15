#ifndef __DISK_H__
#define __DISK_H__

#include "Disk.h"

template<class T>
Disk<T>::Disk(T label)
{
    this->label = label;
}

template<class T>
const T Disk<T>::getLabel()
{
    return label;
};

#endif // __DISK_H__