all: experiment

experiment: experiment.o 
	g++ -Wall -o experiment experiment.o



experiment.o: experiment.cpp quicksort.h 
	g++ -Wall -o experiment.o -c experiment.cpp

clean:
	rm -f experiment *.o
