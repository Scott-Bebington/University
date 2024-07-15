main: main.o IsDivisible.o IsEvenOdd.o IsGreater.o IsPrimeNumber.o IsSmaller.o NumberTester.o TesterInterface.o ValueDependantTester.o ValueIndependantTester.o
	g++ -o main main.o IsDivisible.o IsEvenOdd.o IsGreater.o IsPrimeNumber.o IsSmaller.o NumberTester.o TesterInterface.o ValueDependantTester.o ValueIndependantTester.o

main.o: main.cpp NumberTester.o
	g++ -c main.cpp
	
IsDivisible.o: IsDivisible.cpp IsDivisible.h
	g++ -c IsDivisible.cpp

IsEvenOdd.o: IsEvenOdd.cpp IsEvenOdd.h
	g++ -c IsEvenOdd.cpp

IsGreater.o: IsGreater.cpp IsGreater.h
	g++ -c IsGreater.cpp

IsPrimeNumber.o: IsPrimeNumber.cpp IsPrimeNumber.h
	g++ -c IsPrimeNumber.cpp

IsSmaller.o: IsSmaller.cpp IsSmaller.h
	g++ -c IsSmaller.cpp

NumberTester.o: NumberTester.cpp NumberTester.h
	g++ -c NumberTester.cpp

TesterInterface.o: TesterInterface.cpp TesterInterface.h
	g++ -c TesterInterface.cpp

ValueDependantTester.o: ValueDependantTester.cpp ValueDependantTester.h
	g++ -c ValueDependantTester.cpp

ValueIndependantTester.o: ValueIndependantTester.cpp ValueIndependantTester.h
	g++ -c ValueIndependantTester.cpp

run: main
	./main
	
clean: 
	rm *.o main