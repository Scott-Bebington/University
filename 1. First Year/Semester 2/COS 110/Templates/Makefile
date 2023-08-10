run: main
	./main

main: example.o
	g++ -o main example.o

example.o: example.cpp
	g++ -c example.cpp

clean: main
	rm *.o main *~
