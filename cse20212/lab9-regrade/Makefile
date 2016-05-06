CMP = g++
MAIN = main
MAIN2 = mainTree
CLASS = NDvector
FLAGS = -Wall -g --std=c++11

all: $(MAIN) $(MAIN2)

$(MAIN): $(MAIN).o CardDeck.o
	$(CMP) $(FLAGS) -o $@ $^

$(MAIN2): $(MAIN2).o
	$(CMP) $(FLAGS) -o $@ $^

$%.o: $%.cpp 
	$(CMP)  -c $^

clean:
	rm $(MAIN) *.o