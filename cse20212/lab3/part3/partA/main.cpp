//main.cpp
//AUthors: Kat Herring and Kate Barlock
//driver program for Blackbeard's bank

#include "CheckingAccount.h"
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

	return 0;
}