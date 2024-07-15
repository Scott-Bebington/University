#include <iostream>
#include "Chatroom.h"
#include "Chatter.h"

using namespace std;


int main() {
  Chatroom* cr = new ModuleChatroom("COS214");

  Chatter* student[2];

  Chatter* lecturer = new Lecturer();
  student[0] = new Student();
  student[1] = new Student();

  lecturer->reg(cr);
  student[0]->reg(cr);
  student[1]->reg(cr);

  student[0]->sendMessage();
  student[0]->sendMessage();
  student[1]->sendMessage();
  lecturer->sendMessage();

  student[1]->leave();
  lecturer->leave();
  lecturer->sendMessage();

  delete lecturer;
  for (int i = 0; i < 2; i++)
    delete student[i];

  delete cr;

  return 0;
}
