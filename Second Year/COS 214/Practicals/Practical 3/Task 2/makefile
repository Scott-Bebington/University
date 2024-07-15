CC = g++
CFLAGS = -std=c++11

all: main run clean

main: main.o Menu.o lair.o Traps.o bank.o engine.o storyteller.o hero.o research.o
	$(CC) $(CFLAGS) -o main main.o Menu.o lair.o Traps.o bank.o engine.o storyteller.o hero.o research.o

main.o: main.cpp Menu.h lair.h Traps.h
	$(CC) $(CFLAGS) -c main.cpp

Menu.o: Menu.cpp Menu.h lair.h Traps.h bank.h
	$(CC) $(CFLAGS) -c Menu.cpp

lair.o: lair.cpp lair.h Traps.h
	$(CC) $(CFLAGS) -c lair.cpp

Traps.o: Traps.cpp Traps.h
	$(CC) $(CFLAGS) -c Traps.cpp

bank.o: bank.cpp bank.h
	$(CC) $(CFLAGS) -c bank.cpp

engine.o: engine.cpp engine.h lair.h Traps.h bank.h storyteller.h research.h
	$(CC) $(CFLAGS) -c engine.cpp

hero.o: hero.cpp hero.h
	$(CC) $(CFLAGS) -c hero.cpp

storyteller.o: storyteller.cpp storyteller.h
	$(CC) $(CFLAGS) -c storyteller.cpp

research.o: Research.cpp Research.h
	$(CC) $(CFLAGS) -c Research.cpp

run:
	./main

clean:
	rm -f *.o main
