CMP = g++
MAIN = main
CLASS = BankAccount
CLASS2 = CheckingAccount
CLASS3 = BoatLoan


$(MAIN): $(CLASS).o $(MAIN).o $(CLASS3).o $(CLASS2).o
	$(CMP) -o $(MAIN) $(CLASS).o $(CLASS3).o $(CLASS2).o $(MAIN).o

$(MAIN).o: $(MAIN).cpp
	$(CMP) -c -g $(MAIN).cpp

$(CLASS).o: $(CLASS).cpp
	$(CMP) -c -g $(CLASS).cpp

$(CLASS2).o: $(CLASS2).cpp
	$(CMP) -c -g $(CLASS2).cpp

$(CLASS3).o: $(CLASS3).cpp
	$(CMP) -c -g $(CLASS3).cpp	

clean:
	rm $(MAIN) *.o