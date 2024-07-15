/*
//
//  ActivityExample.cpp
//  
//
//  Created by Linda Marshall on 2020/09/13.
//
// Remember to compile and link using at least the c++14 standard.
// 		Compile: g++ -std=c++14 -c ActivityExample.cpp
//		Link: g++ -std=c++14 ActivityExample.o -o ActivityExample
*/


#include <iostream>
#include <thread>

using namespace std ;


void goBowling();
void bunjyJump();
void stayHome();
void study();

int main() {
	int age;

	cout << " Please enter your age : ";
	cin >> age;


	
	if(age > 60)
		goBowling();
	else if ( age > 21)
		bunjyJump();
	else {
		thread stayHomeThread = thread ( stayHome );
		thread studyThread = thread ( study );
		// Synchronise the threads
		stayHomeThread.join(); // spawn the thread that calls stayHome
		studyThread.join(); // spawn the thread that calls study
		cout << "Actions while threads are running " << endl;
		stayHomeThread.detach();
		studyThread.detach();
		
	}
	
	return 0;
}

void goBowling() {
	cout << "Enjoy the day playing bowls " << endl;
}

void bunjyJump() {
	cout << "Drive to the precipice, " ;
	cout << " attach the bunjy cord and jump ! ! ! ! " << endl;
}

void stayHome() {
	cout << "Stay Home" << endl;
}

void study() {
	cout << "Study" << endl;
}

