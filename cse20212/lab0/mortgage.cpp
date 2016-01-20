//mortgage.cpp
//functions for Mortgage class
//Author: Kat Herring

#include "mortgage.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//constructor
Mortgage::Mortgage() {
	principal = 10000;
	rate = 5;
	payment = 500;
	interestPaymentCalc();
}
Mortgage::Mortgage(double princ, double r, double pay) {
	if(princ<=0) {
		cout << "Error: Principal must be greater than 0!" << endl;
	} else {
		principal = princ;
	} 
	if(r<0) {
		cout << "Error: Interest rate must be greater than 0!" << endl;
	} else {
		rate = r;
	}

	interestPaymentCalc(); //finds amount due in interest per month
	if(pay<=interestPayment+1) { //minimum payment
		cout << "Error: Payment amount not high enough!" << endl;
	} else {
		payment = pay;
	}
}
void Mortgage::amortize() {
//creates amortization table
	int month = 0;
	double balance = principal; //sets initial balance

	cout << "Month  Payment  Interest  Balance" << endl;
	while(balance>.001) {
		month++; //increment month
		if(balance<=payment) { //final payment
			payment = balance + interestPaymentCalc(balance);
		}

		
		cout << setw(5) << month;
		cout << setw(8) << payment;
		cout << setw(10) << interestPaymentCalc(balance);
		balance = abs(balance - payment + interestPaymentCalc(balance));
		//absolute value used so final balance is "positive" zero
		cout << setw(10) << balance << endl;		
	}
}
void Mortgage::credit(double credit) {

	if(credit<0) {
		cout << "Error: Credit must be greater than 0!" << endl;
	} else {
		principal -= credit;
	}
}
double Mortgage::getPrincipal() {
	return principal;
}
void Mortgage::interestPaymentCalc() {
	interestPayment = rate/100*principal/12; //amount paid in interest each month
}
double Mortgage::interestPaymentCalc(double balance) {
	return rate/100*balance/12; //returns interest paid on balance with payment
}