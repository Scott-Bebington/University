	
main: main.o Wizard.o Character.o Fighter.o Druid.o
	g++ -o main main.o Wizard.o Character.o Fighter.o Druid.o

main.o: main.cpp Wizard.o Character.o Fighter.o Druid.o
	g++ -c main.cpp
	
Character.o: Character.cpp Character.h
	g++ -c Character.cpp
	
Wizard.o: Wizard.cpp Wizard.h
	g++ -c Wizard.cpp
	
Fighter.o: Fighter.cpp Fighter.h
	g++ -c Fighter.cpp
	
Druid.o: Druid.cpp Druid.h
	g++ -c Druid.cpp
	
run: main
	./main
	
clean: 
	rm *.o main *~
