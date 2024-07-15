ofiles = main.o rectangled.o
gpp_o = g++ -c -std=c++98
main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: main.cpp rectangle.h
	$(gpp_o) main.cpp

chessboard.o: rectangle.cpp rectangl.h
	$(gpp_o) rectangl.cpp

run: main
	./main
clean:
	rm *.o main