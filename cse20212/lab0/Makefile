mortgage: mortgage.o main.o
	g++ -o mortgage main.o mortgage.o

main.o: main.cpp
	g++ -c main.cpp

mortgage.o: mortgage.cpp mortgage.hpp
	g++ -c mortgage.cpp

clean:
	rm mortgage *.o