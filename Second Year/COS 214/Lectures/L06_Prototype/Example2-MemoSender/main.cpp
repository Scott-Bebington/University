/*
COS 121 - Template Method
August 4, 2011
Christoph Stallmann
*/

#include "memosender.h"

using namespace std;

int main()
{
	MemoSender sender("August 18, 2020", "Please remember the online meeting tomorrow at 10h30!", "Greetings, your Boss");

	string emails[6] = {"p.dool@cos214.ac.za", "p.dool@cos214.ac.za", "k.hope@cos214.ac.za", "r.reed@cos214.ac.za", "l.nkosi@cos214.ac.za", "t.dejager@cos214.ac.za"};

	sender.sendBatch(emails, 6);

	return 1;
}
