CC = g++
CFLAGS = -std=c++23

all: TreeSelfDestruct run clean

TreeSelfDestruct: TreeSelfDestruct.o
	$(CC) $(CFLAGS) -o TreeSelfDestruct TreeSelfDestruct.o

TreeSelfDestruct.o: TreeSelfDestruct.cpp
	$(CC) $(CFLAGS) -c TreeSelfDestruct.cpp

run:
	./TreeSelfDestruct

clean:
	rm -f *.o TreeSelfDestruct
