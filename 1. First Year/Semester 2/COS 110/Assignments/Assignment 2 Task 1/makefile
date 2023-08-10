main: main.o matrix.o arithmetic.o vector.o
	g++ -o main main.o matrix.o arithmetic.o vector.o

main.o: main.cpp matrix.o
	g++ -c main.cpp
	
matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp

vector.o: vector.cpp vector.h
	g++ -c vector.cpp

arithmetic.o: arithmetic.cpp arithmetic.h
	g++ -c arithmetic.cpp

run: main
	./main
	
clean: 
	rm *.o main