#ifndef __MESSAGE_H__
#define __MESSAGE_H__


#include <string>

using namespace std;

class Message
{
    private:
        string text;
    public:
        Message *next;
        Message(string t);
        string getText();
};

#endif // __MESSAGE_H__