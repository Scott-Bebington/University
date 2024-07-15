run: main
	./main

main: bubble.o
	g++ -o main bubble.o

bubble.o: bubble.cpp
	g++ -c bubble.cpp

clean: main
	rm *.o main *~
