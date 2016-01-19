CMP = g++
MAIN = main
CLASS = C4Col

$(MAIN): $(CLASS).o $(MAIN).o
	$(CMP) -o $(MAIN) $(CLASS).o $(MAIN).o

$(MAIN).o: $(MAIN).cpp
	$(CMP) -c $(MAIN).cpp

$(CLASS).o: $(CLASS).cpp $(CLASS).hpp
	$(CMP) -c $(CLASS).cpp

clean:
	rm $(MAIN) *.o