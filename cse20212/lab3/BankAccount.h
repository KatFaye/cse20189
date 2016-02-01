//BankAccount.h
//class definition for BankAccount
//Authors: Kat Herring and Kate Barlock

#include <string>

#ifndef _BANKACCOUNT_H_
#define _BANKACCOUNT_H_

class BankAccount {
public:
	BankAccount(int balance = 0);
	int getBalance();
	void setBalance(int);
	void setMinimumBalance(int);
	void setPirateRate(double);
	int getMinimumBalance();
	double getPirateRate();
	virtual void print() const = 0; //makes this an abstract class

private:
	int balance; //balance of account; recorded in dubloons
	int minimumBalance; //dubloons
	double pirateRate; //how much of your balance Blackbeard takes for security reasons

};

#endif //_BANKACCOUNT_H_