#ifndef MagicItem_H
#define MagicItem_H

#include <string>
using namespace std;

class MagicItem {
 public:

  MagicItem(string, int, double);
  ~MagicItem() {};

  string getTitle() const;
  int getMagica() const;
  double getWeight() const;
	  
  bool operator< (MagicItem&);
  
 private:
  int magica;
  string title;
  double weight;
};

#endif
