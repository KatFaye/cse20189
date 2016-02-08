//boatLoan.h
//Class definition for boatLoan
//Authors: Kate Barlock and Kat Herring

#include "BankAccount.h"

#ifndef _BOATLOAN_H_
#define _BOATLOAN_H_

class BoatLoan : public BankAccount {

public:
	BoatLoan(int balance = 10000, int paymentSchedule = 1, int pirateRate = 15, int maxLootStorage = 2000, int numOfCannons = 20, string boatName = "The Flying Dutchman", int Payment = 500);
	virtual void print(); //prints status of boat, crew, and account
	virtual void deposit(int Deposit); //put money towards paying off loan (besides regular payment)
	void printLoanTable();
	int getMaxLootStorage();
	void setMaxLootStorage(int maxlootstorage);
	int getNumOfCannons();
	void setNumOfCannons(int numCannons);
	string getBoatName();
	void setBoatName(string boatname);
	void setPayment(int payment);
	
private:
	void calcRemainingMonths();
	double Payment; //normal payment (in dubloons)
	int numberofMonths; //remaining months until boat is paid off
	int maxLootStorage; //in sqft
	int numOfCannons; //number of cannons on loaned ship
	string boatName;

};

#endif //_BOATLOAN_H_