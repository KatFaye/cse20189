CMP = g++
MAIN = main
CLASS = BankAccount
CLASS2 = CheckingAccount
CLASS3 = BoatLoan


$(MAIN): $(CLASS).o $(MAIN).o $(CLASS3).o $(CLASS2).o
	$(CMP) -o $(MAIN) $(CLASS).o $(CLASS3).o $(CLASS2).o $(MAIN).o

$(MAIN).o: $(MAIN).cpp
	$(CMP) -c $(MAIN).cpp

$(CLASS).o: $(CLASS).cpp
	$(CMP) -c $(CLASS).cpp

$(CLASS2).o: $(CLASS2).cpp
	$(CMP) -c $(CLASS2).cpp

$(CLASS3).o: $(CLASS3).cpp
	$(CMP) -c $(CLASS3).cpp	

clean:
	rm $(MAIN) *.o