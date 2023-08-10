// constructing lists
#include <iostream>
#include <list>
using namespace std;

int main()
{

  list<int> first; // empty list of ints

  list<int> second(5, 100); // four ints with value 100
  cout << "The contents of second are: ";
  for (list<int>::iterator it = second.begin(); it != second.end(); it++)
    cout << *it << ' ';

  cout << '\n';

  list<int> third(second.begin(), second.end()); // iterating through second
  cout << "The contents of third are: ";
  for (list<int>::iterator it = third.begin(); it != third.end(); it++)
    cout << *it << ' ';

  cout << '\n';

  list<int> fourth(third); // a copy of third
  cout << "The contents of fourth are: ";
  for (list<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
    cout << *it << ' ';

  cout << '\n';

  /*
    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

     std::cout << "The contents of fifth are: ";
    for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
      std::cout << *it << ' ';

    std::cout << '\n';*/

  return 0;
}
