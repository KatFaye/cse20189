//main.cpp
//AUthors: Kat Herring and Kate Barlock
//driver program for Blackbeard's bank

#include "CheckingAccount.h"
#include "BoatLoan.h"
#include <iostream>
#include <iomanip>

using namespace std;
int main(void) {

	//create check account object
	cout << "*** Testing Checking Account ***" << endl;
	CheckingAccount c1("Jack Sparrow", "Black Pearl", 1000);
	c1.print();
	cout << "After crediting 500:" << endl;
	c1.deposit(500); //test that deposit function works
	c1.print();

	//test boat loan
	cout << "*** Testing Boat Loan ***" << endl;
	BoatLoan b1;
	b1.printLoanTable(); //print out loan table (currnet balance, payment, interest over every month of loan)
	b1.print(); //print account status
	
	cout << endl << "*** Test Deposit, then reprint Boat Loan ***" << endl;
	b1.deposit(500); //demonstrate deposit ability
	b1.printLoanTable(); //print out loan table (currnet balance, payment, interest over every month of loan)
	b1.print(); //print account status

	return 0;
}