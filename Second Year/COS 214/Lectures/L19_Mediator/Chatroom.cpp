#include <iostream>
#include <vector>
#include "Chatroom.h"
#include "Chatter.h"


using namespace std;

Chatroom::Chatroom() : nextId(0) {}

int Chatroom::registerMe(Chatter* me){
  Participant* person = new Participant();
  person->chatter = me;
  person->id      = nextId++;
  participant.push_back(person);
  cout<<person->id<<" has just registered."<<endl;
  return person->id;
}

void Chatroom::broadcast(string msg) {
  // Must check is the participant is still registered before sending the message.
  vector<Participant*>::iterator it;

  for (it = participant.begin(); it != participant.end(); ++it) {
    (*it)->chatter->receiveMessage("Broadcast: "+msg);
  }
}

bool Chatroom::talkTo(int id, string msg){
  // Must check is the participant is still registered before sending the message.
  vector<Participant*>::iterator it;
  bool found = false;

  it = participant.begin();
  while ((it != participant.end()) && (!found)) {
    if ((*it)->id == id) {
      found = true;
      (*it)->chatter->receiveMessage(msg);
    } else {
      it++;
    }
  }   
  return found;
}

void Chatroom::leave(int id) {
  vector<Participant*>::iterator it;
  bool found = false;
  int count = 0;

  it = participant.begin();
  while ((it != participant.end()) && (!found)) {
    if ((*it)->id == id) {
      found = true;
    } else {
      it++;
      count++;
    }
  }   
  if (found) {
    cout<<(*it)->id<<" has just left."<<endl; 
    participant.erase(it);

  }
}


ModuleChatroom::ModuleChatroom(string n)  {
  name = n;
}
