/*
COS 121 - Prototype
August 10, 2011
Christoph Stallmann
*/

#ifndef MEMOSENDER_H
#define MEMOSENDER_H

#include "memo.h"

class MemoSender
{

	public:
		MemoSender(string date, string message, string signature);
		~MemoSender();
		void sendBatch(string *emailAddresses, int numberOfEmails);

	private:
		void sendSingle(string emailAddress, Memo *memo);
		Memo* mPrototype;

};

#endif

