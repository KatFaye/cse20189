CMP = g++
MAIN = main
CLASS = CardDeck


$(MAIN): $(CLASS).o $(MAIN).o
	$(CMP) -o $(MAIN) $(CLASS).o $(MAIN).o

$(MAIN).o: $(MAIN).cpp
	$(CMP) -c -g $(MAIN).cpp

$(CLASS).o: $(CLASS).cpp
	$(CMP) -c -g $(CLASS).cpp

clean:
	rm $(MAIN) *.o