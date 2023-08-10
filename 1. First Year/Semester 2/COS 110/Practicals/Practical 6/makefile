main: main.o Cargo.o Controller.o Exceptions.o Passenger.o Plane.o SecretCargo.o
	g++ -o main main.o Cargo.o Controller.o Exceptions.o Passenger.o Plane.o SecretCargo.o

main.o: main.cpp Controller.o
	g++ -c main.cpp
	
Cargo.o: Cargo.cpp Cargo.h
	g++ -c Cargo.cpp

Controller.o: Controller.cpp Controller.h
	g++ -c Controller.cpp

Exceptions.o: Exceptions.cpp Exceptions.h
	g++ -c Exceptions.cpp

Passenger.o: Passenger.cpp Passenger.h
	g++ -c Passenger.cpp

Plane.o: Plane.cpp Plane.h
	g++ -c Plane.cpp

SecretCargo.o: SecretCargo.cpp SecretCargo.h
	g++ -c SecretCargo.cpp

run: main
	./main
	
clean: 
	rm *.o main