CC = g++
CFLAGS = -std=c++23

all: main run clean

main: main.o org.o orgStructure.o individual.o
	$(CC) $(CFLAGS) -o main main.o org.o orgStructure.o individual.o

main.o: main.cpp orgStructure.h org.h individual.h
	$(CC) $(CFLAGS) -c main.cpp

org.o: org.cpp org.h
	$(CC) $(CFLAGS) -c org.cpp

orgStructure.o: orgStructure.cpp orgStructure.h org.h
	$(CC) $(CFLAGS) -c orgStructure.cpp

individual.o: individual.cpp individual.h org.h
	$(CC) $(CFLAGS) -c individual.cpp

run:
	./main

clean:
	rm -f *.o main
