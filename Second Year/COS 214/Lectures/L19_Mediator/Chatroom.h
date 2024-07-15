#ifndef CHATROOM_H
#define CHATROOM_H

#include <string>
#include <vector>

#include "Chatter.h"

using namespace std;

class Participant {
  public:
    int       id;
    Chatter*  chatter;
};

class Chatroom {  // Mediator
  public:
    Chatroom();
    int registerMe(Chatter*); // register yourself and receive your id
    void broadcast(string);
    bool talkTo(int,string);
    void leave(int);
//    virtual ~Chatroom();  // Will need to implement.  Cannot remove chatters but can make them 0
                            // The Participants in the vector can then be removed. 
  protected:
    vector<Participant*> participant;
    int              nextId;
};

class ModuleChatroom : public Chatroom {  // Concrete Mediator
  public:
    ModuleChatroom(string);
//    virtual ~ModuleChatroom();
  protected:
    string name;
};


#endif
