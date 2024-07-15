CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: State_Memory run clean

State_Memory: State_Memory.o
	g++ -o State_Memory State_Memory.o

State_Memory.o: State_Memory.cpp
	g++ -c -std=c++11 State_Memory.cpp


run:
	./State_Memory

clean: 
	rm -f *.o State_Memory

