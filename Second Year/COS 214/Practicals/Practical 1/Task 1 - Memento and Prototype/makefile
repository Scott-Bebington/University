CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: main run clean

main: main.o ship.o cargoShip.o cargoMemento.o
	g++ -o main main.o ship.o cargoShip.o cargoMemento.o

main.o: main.cpp ship.h cargoShip.h cargoMemento.h
	g++ -c -std=c++11 main.cpp

ship.o: ship.cpp ship.h
	g++ -c -std=c++11 ship.cpp

cargoShip.o: cargoShip.cpp cargoShip.h ship.h
	g++ -c -std=c++11 cargoShip.cpp

cargoMemento.o: cargoMemento.cpp cargoMemento.h
	g++ -c -std=c++11 cargoMemento.cpp

run:
	./main

clean: 
	rm -f *.o main

