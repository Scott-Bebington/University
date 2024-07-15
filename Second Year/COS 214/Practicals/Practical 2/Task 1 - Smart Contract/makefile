CC = g++
CFLAGS = -std=c++23

all: main run clean

main: main.o Context.o State.o Negotiation.o Tentatively_Accepted.o Accepted.o Completed.o Rejected.o
	$(CC) $(CFLAGS) -o main main.o Context.o State.o Negotiation.o Tentatively_Accepted.o Accepted.o Completed.o Rejected.o

main.o: main.cpp Context.h
	$(CC) $(CFLAGS) -c main.cpp

Context.o: Context.cpp Context.h State.h
	$(CC) $(CFLAGS) -c Context.cpp

State.o: State.cpp State.h Context.h
	$(CC) $(CFLAGS) -c State.cpp

Negotiation.o: Negotiation.cpp Negotiation.h Context.h State.h
	$(CC) $(CFLAGS) -c Negotiation.cpp

Tentatively_Accepted.o: Tentatively_Accepted.cpp Tentatively_Accepted.h Context.h State.h
	$(CC) $(CFLAGS) -c Tentatively_Accepted.cpp

Accepted.o: Accepted.cpp Accepted.h Context.h State.h
	$(CC) $(CFLAGS) -c Accepted.cpp

Completed.o: Completed.cpp Completed.h Context.h State.h
	$(CC) $(CFLAGS) -c Completed.cpp

Rejected.o: Rejected.cpp Rejected.h Context.h State.h
	$(CC) $(CFLAGS) -c Rejected.cpp

run:
	./main

clean:
	rm -f *.o main
