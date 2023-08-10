ofiles = Pointers.o 
gpp_o = g++ -c -std=c++98
main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: Pointers.cpp
	$(gpp_o) main.cpp

Pointers.o: Pointers.cpp
	$(gpp_o) Pointers.cpp

run: main
	./main
clean:
	rm *.o main
