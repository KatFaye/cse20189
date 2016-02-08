//checkingAccount.h
//Class definition of Blackbeard's checking accounts
//Authors: Kat Herring and Kate Barlock

#include "BankAccount.h"
using namespace std;

#ifndef _CHECKINGACCOUNT_H_
#define _CHECKINGACCOUNT_H_

class CheckingAccount : public BankAccount {
	
public:
	CheckingAccount(string accountHolder, string crewAffiliation, int balance, int minimumBalance = 500);

	void setMinimumBalance(int);
	int getMinimumBalance();
	void setAccountHolder(string);
	string getAccountHolder();

	void setCrewAffiliation(string);
	string getCrewAffiliation();

	int nextPayment(); //amount due at next payment date (in dubloons)
	virtual void deposit(int); // credit money to account
	virtual void print(); //print the account and user status

private:

	string accountHolder;
	string crewAffiliation; //pirates member associated with
	int minimumBalance; //dubloons
};

#endif //_CHECKINGACCOUNT_H_