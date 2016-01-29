CMP = g++
MAIN = main
CLASS = Rational


$(MAIN): $(CLASS).o $(MAIN).o
	$(CMP) -o $(MAIN) $(CLASS).o  $(MAIN).o

$(MAIN).o: $(MAIN).cpp
	$(CMP) -c $(MAIN).cpp

$(CLASS).o: $(CLASS).cpp
	$(CMP) -c $(CLASS).cpp

clean:
	rm $(MAIN) *.o