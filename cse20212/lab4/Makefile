CMP = g++
MAIN = main
CLASS = CardDeck
GAME = blackjack
FLAGS = -Wall

all: $(MAIN) $(GAME)

$(MAIN): $(CLASS).o $(MAIN).o
	$(CMP) -o $@ $^

$(GAME): $(CLASS).o $(GAME).o
	$(CMP) -o $@ $^

$%.o: $%.cpp
	$(CMP) -c $(FLAGS) $^

clean:
	rm $(MAIN) $(GAME) *.o