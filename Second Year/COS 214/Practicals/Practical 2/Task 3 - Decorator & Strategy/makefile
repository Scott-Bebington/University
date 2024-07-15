ofiles = main.o Calculator.o numericCalculator.o booleanCalculator.o test.o numericTest.o booleanTest.o testable.o testBed.o testDecorator.o beforeTest.o afterTest.o

gpp_o = g++ -c -std=c++23

main: $(ofiles)
	g++ -std=c++11 $(ofiles) -o main

main.o: main.cpp Calculator.h numericCalculator.h booleanCalculator.h test.h numericTest.h booleanTest.h testable.h testBed.h testDecorator.h beforeTest.h afterTest.h
	$(gpp_o) main.cpp

Calculator.o: Calculator.cpp Calculator.h
	$(gpp_o) Calculator.cpp

numericCalculator.o: numericCalculator.cpp numericCalculator.h Calculator.h
	$(gpp_o) numericCalculator.cpp

booleanCalculator.o: booleanCalculator.cpp booleanCalculator.h Calculator.h
	$(gpp_o) booleanCalculator.cpp

test.o: test.cpp test.h Calculator.h
	$(gpp_o) test.cpp

numericTest.o: numericTest.cpp numericTest.h test.h Calculator.h
	$(gpp_o) numericTest.cpp

booleanTest.o: booleanTest.cpp booleanTest.h test.h Calculator.h
	$(gpp_o) booleanTest.cpp

testable.o: testable.cpp testable.h test.h
	$(gpp_o) testable.cpp

testBed.o: testBed.cpp testBed.h testable.h
	$(gpp_o) testBed.cpp

testDecorator.o: testDecorator.cpp testDecorator.h testable.h
	$(gpp_o) testDecorator.cpp

beforeTest.o: beforeTest.cpp beforeTest.h testDecorator.h testable.h
	$(gpp_o) beforeTest.cpp

afterTest.o: afterTest.cpp afterTest.h testDecorator.h testable.h
	$(gpp_o) afterTest.cpp

run: main
	./main

clean:
	rm *.o main

all: main run clean