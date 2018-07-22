all:
	rm -f main
	rm -f pgmIO.o
	rm -f output.pgm
	g++ -c pgmIO.h -o pgmIO.o -std=c++11 -w
	g++ pgmIO.o image.cpp main.cpp -o main -std=c++11 
	./main && open -a Preview output.pgm

main: all
