pt: memo.o memosender.o main.o
	g++ -Wall memo.o memosender.o main.o -o pt

memo.o: memo.cpp memo.h
	g++ -Wall -c memo.cpp

memosender.o: memosender.cpp memosender.h
	g++ -Wall -c memosender.cpp

main.o: main.cpp
	g++ -Wall -c main.cpp

clean:
	rm pt memo.o memosender.o main.o
