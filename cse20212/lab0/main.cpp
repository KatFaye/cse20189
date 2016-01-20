//main.cpp
//main program for mortgage calculator (redux)
//Author: Kat Herring

#include <iostream>
#include <iomanip>
#include "mortgage.hpp"

using namespace std;

int main(void) {

	double creditAmount = 10000;

	Mortgage defaultMortgage; //creates default-initialized object
	Mortgage secondMortgage(100000, 5.0, 500); //creates non-default object

	secondMortgage.credit(creditAmount); //credits account
	cout << fixed << setprecision(2) << "Current balance after crediting account $" << creditAmount;
	cout << fixed << setprecision(2) << ": $" << secondMortgage.getPrincipal() << endl;
	cout << "Amortization schedule for first mortgage: " << endl;
	defaultMortgage.amortize();
	return 0;
}