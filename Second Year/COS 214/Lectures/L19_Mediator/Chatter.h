#ifndef CHATTER_H
#define CHATTER_H

#include <string>


using namespace std;

class Chatroom;

class Chatter { // Colleague
  public:
    Chatter();
    virtual void receiveMessage(string) = 0;
    virtual void sendMessage() = 0;
    void reg(Chatroom*);
    void leave();
    virtual ~Chatter();
  protected:
    Chatroom* chatroom; 
    int       myId;
};


class Student : public Chatter {
  public:
    Student();
    virtual void receiveMessage(string);
    virtual void sendMessage();
};


class Lecturer : public Chatter {
  public:
    Lecturer();
    virtual void receiveMessage(string);
    virtual void sendMessage();
};

#endif
