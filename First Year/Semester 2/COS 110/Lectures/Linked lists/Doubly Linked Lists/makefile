main: main.o
	g++ -o main main.o

main.o: main.cpp
	g++ -c -std=c++98 main.cpp

run: clean main
	./main
		
clean: 
	rm -f *.o main
