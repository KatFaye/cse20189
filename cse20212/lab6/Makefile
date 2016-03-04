CMP = g++
MAIN = main
CLASS = puzzle
FLAGS = -Wall -g

all: $(MAIN)

$(MAIN): $(MAIN).o
	$(CMP) -o $@ $^

$%.o: $%.cpp 
	$(CMP) -c $(FLAGS) $^

clean:
	rm $(MAIN) *.o