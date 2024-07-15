CC = g++
CFLAGS = -std=c++23

all: Graphic_MemoryFixed run clean

Graphic_MemoryFixed: Graphic_MemoryFixed.o
	$(CC) $(CFLAGS) -o Graphic_MemoryFixed Graphic_MemoryFixed.o

Graphic_MemoryFixed.o: Graphic_MemoryFixed.cpp
	$(CC) $(CFLAGS) -c Graphic_MemoryFixed.cpp

run:
	./Graphic_MemoryFixed

clean:
	rm -f *.o Graphic_MemoryFixed
