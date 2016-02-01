//boatLoan.h
//Class definition for boatLoan
//Authors: Kate Barlock and Kat Herring

#include "BankAccount.h"

#ifndef _BOATLOAN_H_
#define _BOATLOAN_H_

class BoatLoan : public BankAccount {
public:
	int getMaxLootStorage();
	void setMaxLootStorage(int);
	int getNumOfCannons();
	void setNumOfCannons(int);
	string getBoatName();
	void setBoatName(string);
	virtual void print(); //prints status of boat, crew, and account
	
private:
	int maxLootStorage;
	int numOfCannons;
	string boatName; //the crew that manages the boat loan

};

#endif //_BOATLOAN_H_