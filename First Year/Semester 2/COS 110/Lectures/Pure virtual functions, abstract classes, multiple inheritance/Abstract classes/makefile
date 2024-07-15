main: main.o Polygon.o Rectangle.o Triangle.o
	g++ -o main main.o Polygon.o Rectangle.o Triangle.o
	
main.o: main.cpp 
	g++ -c main.cpp
	
Polygon.o: Polygon.cpp  
	g++ -c  Polygon.cpp

Rectangle.o: Rectangle.cpp 
	g++ -c Rectangle.cpp
	
Triangle.o: Triangle.cpp 
	g++ -c Triangle.cpp

run: main
	./main
	
clean:
	rm *.o main