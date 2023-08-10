main: main.o Person.o Superhero.o Archenemy.o
	g++ -o main main.o Person.o Superhero.o Archenemy.o

main.o: main.cpp Person.o Superhero.o
	g++ -c main.cpp
	
Person.o: Person.cpp Person.h
	g++ -c Person.cpp
	
Superhero.o: Superhero.cpp Superhero.h
	g++ -c Superhero.cpp
	
Archenemy.o: Archenemy.cpp Archenemy.h
	g++ -c Archenemy.cpp

run: main
	./main
	
clean: *.o
	rm *.o main
		
