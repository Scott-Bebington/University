ofiles = studentmain.o chesspiece.o chessboard.o 
gpp_o = g++ -c -std=c++98
main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

main.o: studentmain.cpp chessboard.h chesspiece.h
	$(gpp_o) main.cpp

chessboard.o: chessboard.cpp chessboard.h
	$(gpp_o) chessboard.cpp

chesspiece.o: chesspiece.cpp chesspiece.h chessboard.h
	$(gpp_o) chesspiece.cpp

run: main
	./main
clean:
	rm *.o main
