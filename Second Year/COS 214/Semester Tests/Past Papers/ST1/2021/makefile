CC = g++
CFLAGS = -std=c++23

all: main run clean

main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

run:
	./main

clean:
	rm -f *.o main
