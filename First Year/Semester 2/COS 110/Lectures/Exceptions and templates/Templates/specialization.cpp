// template specialization
#include <iostream>
using namespace std;

// class template:
template <class T>
class mycontainer {
    T element;
  public:
    mycontainer (T arg) {element=arg;}
    T increase () { return ++element; }
};

// class template specialization:
template <>
class mycontainer <char> {
    char element;
  public:
    mycontainer (char arg) {element=arg;}
    
    char increase () {return ++element;}
    
    char uppercase ()
    {
      if ((element>='a')&&(element<='z'))
      element += 'A'-'a';
      return element;
    }
    
    char lowercase ()
    {
      if ((element>='A')&&(element<='Z'))
      element -= 'A'-'a';
      return element;
    }
};

int main () {
  mycontainer<int> myint (7);
  mycontainer<char> mychar ('j');
	
  cout << myint.increase() << endl;
  //cout << myint.uppercase() << endl;
	
	
  cout << mychar.uppercase() << endl;
  cout << mychar.increase() << endl;
  cout << mychar.lowercase() << endl;
  return 0;
}