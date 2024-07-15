CC = g++
CFLAGS = -std=c++23

all: PitStop run clean

PitStop: PitStop.o
	$(CC) $(CFLAGS) -o PitStop PitStop.o

PitStop.o: PitStop.cpp
	$(CC) $(CFLAGS) -c PitStop.cpp

run:
	./PitStop

clean:
	rm -f *.o PitStop
