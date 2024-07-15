main: main.o TwoDArray.o SumArray.o SortArray.o CountArray.o
	g++ -o main main.o TwoDArray.o SumArray.o SortArray.o CountArray.o

main.o: main.cpp TwoDArray.o
	g++ -c main.cpp
	
TwoDArray.o: TwoDArray.cpp TwoDArray.h
	g++ -c TwoDArray.cpp

SumArray.o: SumArray.cpp SumArray.h
	g++ -c SumArray.cpp

SortArray.o: SortArray.cpp SortArray.h
	g++ -c SortArray.cpp

CountArray.o: CountArray.cpp CountArray.h
	g++ -c CountArray.cpp	

run: main
	./main
	
clean: 
	rm *.o main