/*
COS 121 - Prototype
August 10, 2011
Christoph Stallmann
*/

#include "memo.h"

Memo::Memo(string date, string message, string signature)
{
	mDate = date;
	mMessage = message;
	mSignature = signature;
}

Memo::Memo(const Memo& memo)
{
	mDate = memo.mDate;
	mMessage = memo.mMessage;
	mSignature = memo.mSignature;
}

Memo* Memo::clone()
{
	return new Memo(*this);
}

void Memo::send(string email)
{
	cout << "\tThe memo from " << mDate << " was sent to " << email << endl;
	cout << "\t\tMemo message: " << mMessage << endl;
}
