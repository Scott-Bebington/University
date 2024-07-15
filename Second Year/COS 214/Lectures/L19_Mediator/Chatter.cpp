#include <iostream>
//#include <vector>
#include <sstream>

#include "Chatter.h"
#include "Chatroom.h"


Chatter::Chatter() {
  chatroom = 0;
  myId=-1;
}

void Chatter::reg(Chatroom* cr){
  chatroom = cr;
  myId = chatroom->registerMe(this);
}

void Chatter::leave(){
  chatroom->leave(myId);
}

Chatter::~Chatter() {
    //delete chatroom;
    chatroom = 0;
    myId = -1;
}

Student::Student() : Chatter() {
  cout<<"Creating Student"<<endl;
}

void Student::receiveMessage(string msg){
  cout<<myId<<" received msg from "<<msg<<endl;
}

void Student::sendMessage(){
  string toId;
  string msg;
  cout<<"Student "<<myId<<" send message to? ";
  getline(cin,toId,'\n');

  cout<<"Student "<<myId<<" message? ";
  getline(cin,msg,'\n');

  ostringstream convert;
  convert << myId;
  chatroom->talkTo(atoi(toId.c_str()),convert.str()+": "+msg);
}


Lecturer::Lecturer() : Chatter() {
  cout<<"Creating Lecturer"<<endl;
}

void Lecturer::receiveMessage(string msg){
  cout<<myId<<" received msg from "<<msg<<endl;
}

void Lecturer::sendMessage(){
  string msg;
  cout<<"Lecturer "<<myId<<" message? ";
  getline(cin,msg,'\n');

  chatroom->broadcast(msg);
}

