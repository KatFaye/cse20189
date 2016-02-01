//checkingAccount.h
//Class definition of Blackbeard's checking accounts
//Authors: Kat Herring and Kate Barlock

#include "BankAccount.h"

#ifndef _CHECKINGACCOUNT_H_
#define _CHECKINGACCOUNT_H_

class CheckingAccount : public BankAccount {
public:
	void setAccountHolder(string);
	string getAccountHolder();
	void setCrewAffiliation(string);
	string getCrewAffiliation();
	virtual void print(); //print the account and user status

private:
	string accountHolder;
	string crewAffiliation; //pirates member associated with

};

#endif //_CHECKINGACCOUNT_H_