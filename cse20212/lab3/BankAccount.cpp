//BankAccount.cpp
//interface and member functions for BankAccount.cpp
//Author: Kat Herring and Kate Barlock

#include "BankAccount.h"
#include <iostream>
 
using namespace std;

BankAccount::BankAccount(int newBal) {
	balance = newBal; //balance of account
	minimumBalance = 100;

	//change this to while loop
	if(balance<minimumBalance) {
		cout << "Error: Insufficient funds to open an account with Blackbeard" << endl;
	}

	pirateRate = 15; //how much of your balance Blackbeard takes for security reasons; quarterly charge


}