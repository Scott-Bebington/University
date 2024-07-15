/*
COS 121 - Prototype
August 10, 2011
Christoph Stallmann
*/

#include "memosender.h"

MemoSender::MemoSender(string date, string message, string signature)
{
	mPrototype = new Memo(date, message, signature);
}

MemoSender::~MemoSender()
{
	delete mPrototype;
}

void MemoSender::sendBatch(string *emailAddresses, int numberOfEmails)
{
	cout << "Starting to send a batch of emails ..." << endl;
	for(int i = 0; i < numberOfEmails; i++)
	{
		sendSingle(emailAddresses[i], mPrototype->clone());
	}
	cout << "All emails were sent!" << endl;
}

void MemoSender::sendSingle(string emailAddress, Memo *memo)
{
	memo->send(emailAddress);
	delete memo;
	memo = NULL;
}
