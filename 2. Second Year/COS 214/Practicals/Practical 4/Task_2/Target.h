#ifndef TARGET_H
#define TARGET_H

using namespace std;
#include "string"

// Target
class Target {
public:
	virtual string GetNewQuery() = 0;
};

#endif // TARGET_H