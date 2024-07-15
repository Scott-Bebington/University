/*
COS 121 - Prototype
August 10, 2011
Christoph Stallmann
*/

#ifndef MEMO_H
#define MEMO_H

#include <string>
#include <iostream>

using namespace std;

class Memo
{

	public:
		Memo(string date, string message, string signature);
		Memo(const Memo& memo);
		
		Memo* clone();
		void send(string email);

	private:
		string mDate;
		string mMessage;
		string mSignature;

};

#endif

