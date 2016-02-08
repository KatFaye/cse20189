//checkingAccount.cpp
//Implementation of Blackbeard's checking accounts
//Author: Kate Barlock and Kat Herring

#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(string accountName, string crewName, int newBal, int minBal) {

	setAccountHolder(accountName);
	setCrewAffiliation(crewName);
	//ensure that starting balance meets minimum balance requirement
	while(newBal < minBal){ 
		cout << "Error: Insufficient funds to open an account with Blackbeard" << endl; //output error message
		cout << "Please enter a new balance: "; // ask for valid balance
		cin >> newBal; //read in new balance
	} //end while
	account.setBalance(newBal);
}
CheckingAccount::~CheckingAccount() {
	
}
string CheckingAccount::getAccountHolder(){

	return accountHolder;
}

void CheckingAccount::setAccountHolder(string clientName){

	accountHolder = clientName;
}

string CheckingAccount::getCrewAffiliation(){

	return crewAffiliation;
}

void CheckingAccount::setCrewAffiliation(string crewName){

	crewAffiliation = crewName;
}

void CheckingAccount::print() { //print the account and user status
	cout << "Account Summary for " << accountHolder << ":" << endl;
	cout << "==============" << endl;
	cout << "Current Balance: " << account.getBalance() << endl;
	cout << "Upcoming insurance and maintenace fee: " << nextPayment() << endl;
	cout << "Next insurance payment due in " << account.getPaymentSchedule() << " month(s).\n" << endl;

}

void CheckingAccount::deposit(int addBal) {
	int temp;
	temp = account.getBalance() + addBal;
	account.setBalance(temp);
}

int CheckingAccount::nextPayment() {
	return account.getBalance()*account.getPirateRate()/100; //insurance rate
}

int CheckingAccount::getMinimumBalance(){
	return minimumBalance;
}

void CheckingAccount::setMinimumBalance(int minBal){

	while(minBal<0) {
		cout << "Error: Minimum Balance must be greater than zero!" << endl;
		cin >> minBal;
	}
	minimumBalance = minBal;

}