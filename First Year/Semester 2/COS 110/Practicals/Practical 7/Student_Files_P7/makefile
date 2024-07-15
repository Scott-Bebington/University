main: main.o Calendar.o Event.o Utils.h
	g++ -o main main.o Calendar.o Event.o Utils.h

main.o: main.cpp Calendar.o
	g++ -c main.cpp
	
Calendar.o: Calendar.cpp Calendar.h
	g++ -c Calendar.cpp

Event.o: Event.cpp Event.h
	g++ -c Event.cpp

run: main
	./main
	
clean: 
	rm *.o main