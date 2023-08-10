run: main
	./main

main: main.o Artefact.o Inventory.o MagicItem.o SearchableInventory.o
	g++ -static main.o Artefact.o Inventory.o SearchableInventory.o MagicItem.o -o main

main.o:	main.cpp Artefact.h MagicItem.h
	g++ -c main.cpp

Artefact.o:	Artefact.cpp Artefact.h
	g++ -c Artefact.cpp

MagicItem.o:	MagicItem.cpp MagicItem.h
	g++ -c MagicItem.cpp

Inventory.o:	Inventory.cpp Inventory.h
	g++ -c Inventory.cpp

SearchableInventory.o:	SearchableInventory.cpp SearchableInventory.h
	g++ -c SearchableInventory.cpp
clean:
	rm *.o 







