main: main.o Box.o Rectangle.o Cube.o
	g++ -o main main.o Box.o Rectangle.o Cube.o

main.o: main.cpp Box.o Rectangle.o
	g++ -c main.cpp
	
Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -c Rectangle.cpp
	
Box.o: Box.cpp Box.h
	g++ -c Box.cpp
	
Cube.o: Cube.cpp Cube.h
	g++ -c Cube.cpp

run: main
	./main
	
clean: 
	rm *.o main