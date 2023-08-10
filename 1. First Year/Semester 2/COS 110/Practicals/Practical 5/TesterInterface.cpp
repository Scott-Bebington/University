#ifndef COUNTARRAY_CPP
#define COUNTARRAY_CPP

#include "TesterInterface.h"

using namespace std;

TesterInterface::TesterInterface(int maxNumTests)
{
    currNumTesters = 0;
    if (maxNumTests < 1)
    {
        maxNumTesters = 0;
        testers = new NumberTester *[0];
    }
    else
    {
        maxNumTesters = maxNumTests;
        testers = new NumberTester *[maxNumTests];
    }
}

TesterInterface::TesterInterface(TesterInterface *other)
{
    int currNumTesters2 = 0;
    int maxNumTesters2 = 0;
    NumberTester **testers2 = new NumberTester *[0];
    if (other->testers != NULL)
    {
        currNumTesters2 = other->currNumTesters;
        maxNumTesters2 = other->maxNumTesters;
        testers2 = other->testers;
    }
}

TesterInterface::TesterInterface(TesterInterface &other)
{
    int currNumTesters3 = other.currNumTesters;
    int maxNumTesters3 = other.maxNumTesters;
    NumberTester **testers3 = other.testers;
}

TesterInterface::~TesterInterface()
{
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i] != NULL)
        {
            delete testers[i];
        }
    }
    delete[] testers;
}

int TesterInterface::addTester(NumberTester *tester)
{
    if (tester == NULL || currNumTesters == maxNumTesters)
    {
        return -1;
    }
    else
    {
        currNumTesters++;
        NumberTester *tester2 = tester->clone();
        for (int i = 0; i < maxNumTesters; i++)
        {
            if (testers[i] == NULL)
            {
                testers[i] = tester2;
                return i;
            }
        }
    }
}

bool TesterInterface::removeTester(int pos)
{
    if (testers[pos] == NULL)
    {
        return false;
    }
    else if (pos < 0 || pos >= (maxNumTesters))
    {
        return false;
    }
    else
    {
        delete testers[pos];
        testers[pos] = NULL;
        if (testers[pos] == NULL)
        {
            currNumTesters--;
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool TesterInterface::evaluate(int num)
{
    int count = 0;
    if (currNumTesters == 0)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < currNumTesters; i++)
        {
            if (testers[i] != NULL)
            {
                bool temp = testers[i]->evaluate(num);
                if (temp)
                {
                    count++;
                }
            }
        }
        if (count == currNumTesters)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int *TesterInterface::failedTests(int num)
{
    int *array = new int[0];
    int count = 0;
    if (currNumTesters == 0)
    {
        return array;
    }
    else
    {
        array = new int[numberOfFailedTests(num)];
        for (int i = 0; i < currNumTesters; i++)
        {
            if (testers[i] != NULL)
            {
                bool temp = evaluate(num);
                if (temp == false)
                {
                    array[count] = i;
                    count++;
                }
            }
        }
    }
    return array;
}

int TesterInterface::numberOfFailedTests(int num)
{
    int size = 0;
    for (int i = 0; i < currNumTesters; i++)
    {
        bool temp = evaluate(num);
        if (temp == false)
        {
            size++;
        }
    }
    return size;
}

NumberTester *TesterInterface::operator[](int pos)
{
    if (pos < 0 || pos >= maxNumTesters)
    {
        return NULL;
    }
    else
    {
        NumberTester *ptr = testers[pos];
        return ptr;
    }
}

int TesterInterface::getCurrNumTesters() const
{
    return currNumTesters;
}

int TesterInterface::getMaxNumTesters() const
{
    return maxNumTesters;
}

#endif