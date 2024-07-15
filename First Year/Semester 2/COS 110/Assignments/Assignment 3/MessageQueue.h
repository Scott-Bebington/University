#ifndef __MESSAGEQUEUE_H__
#define __MESSAGEQUEUE_H__


#include "Message.h"
#include <string>

using namespace std;

class MessageQueue
{
    private:
        int timeout;
        int current;
        Message* head;
        Message* tail;
    public:
        MessageQueue(int timeout);
        string print();
        void addMessage(Message* m);
        ~MessageQueue();
};
#endif // __MESSAGEQUEUE_H__