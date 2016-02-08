CMP = g++
MAIN = main
CLASS = BankAccount
CLASS2 = CheckingAccount



$(MAIN): $(CLASS).o $(MAIN).o $(CLASS2).o
	$(CMP) -o $(MAIN) $(CLASS).o $(CLASS2).o $(MAIN).o

$(MAIN).o: $(MAIN).cpp
	$(CMP) -c -g $(MAIN).cpp

$(CLASS).o: $(CLASS).cpp
	$(CMP) -c -g $(CLASS).cpp

$(CLASS2).o: $(CLASS2).cpp
	$(CMP) -c -g $(CLASS2).cpp

clean:
	rm $(MAIN) *.o