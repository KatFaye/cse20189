//BankAccount.cpp
//interface and member functions for BankAccount.cpp
//Author: Kat Herring and Kate Barlock

#include "BankAccount.h"
#include <iostream>
#include <cmath>
 
using namespace std; //adding this fixed the string problems

BankAccount::BankAccount(int newBal, int paySchedule, int newRate) { //constructor. make/initialize new bank account class object

	//initialize account
	setPaySchedule(paySchedule);
	setPirateRate(newRate);
	setBalance(newBal);
}
void BankAccount::setPaySchedule(int paySchedule) {
	paymentSchedule = paySchedule;

}
int BankAccount::getPaymentSchedule() {
	return paymentSchedule;
}
int BankAccount::getBalance(){ //return current account balance

	return balance;
}

void BankAccount::setBalance(int newBal){ //set account balance

	balance = newBal; //set account balance

}

double BankAccount::getPirateRate(){ //return pirateRate

	return pirateRate;

}

void BankAccount::setPirateRate(double newRate){ //set pirateRate variable of BankAccount class object

	//error checking:
	while(newRate < 0){ //while the given rate is negative
		cout << "Error: Invalid rate. Must be positive." << endl; //output error message
		cout << "Please enter a new rate: "; // ask for valid rate
		cin >> newRate; //read in new rate
	}

	//set pirateRate
	pirateRate = newRate; //how much of your balance Blackbeard takes for security reasons

}

