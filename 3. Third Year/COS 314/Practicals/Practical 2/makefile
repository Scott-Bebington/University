#add all the files that you need to the files makefile variable below as a space seperated list
files = 

main: main.cpp
	g++ -g $(files) main.cpp -o main

clean:
	rm -f *.o main

run:
	./main

all:
	make clean
	make
	make run