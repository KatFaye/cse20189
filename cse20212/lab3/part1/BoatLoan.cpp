//boatLoan.cpp
//Implementation of boatLoan, which defines the plundered boat
//Authors: Kat Herring and Kate Barlock

#include "BoatLoan.h"
#include <iomanip>
#include <iostream>

BoatLoan::BoatLoan(int bal, int paySched, int pirRate, int newLootMax, int numCan, string newName, int payment) : BankAccount(bal, paySched, pirRate) {

	//initialize boat loan
	setMaxLootStorage(newLootMax);
	setNumOfCannons(numCan);
	setBoatName(newName);
	//setPayment(payment);
	Payment = payment;

}

void BoatLoan::printLoanTable(){

	int month = 0, savePayment; //intialize month counter, payment amount retainer
	int bal = getBalance(); //access private data
	int rate = getPirateRate(); //access private data
	int payFreq = getPaymentSchedule(); //access private data

	cout << endl << boatName << "'s Boat Loan Table:" << endl << "==============" << endl;

	cout << "Month    Payment    Interest        Balance" << endl; //display table header

	while (bal > 0) { //while boat loan has not been paid off

	    int interest = bal * rate/(1200/payFreq); //calculate interest (based on yearly frequency of Payment)
	    bal += interest; //add interest to principal

	    if (bal > Payment) { // if boatLoan is ongoing 
	    	bal -= Payment; //calculate new balance
	    } else { //calculate final Payment info
	    	savePayment = Payment; //save value of payment
	        Payment = bal; //calculate final Payment
	        bal -= Payment; //bring balance to 0
	    }
	    month+= payFreq; //increase month counter
	    //print table row
		cout << setw(3) << month << setw(10) << Payment << setw(12) << interest << setw(16) << bal << endl; //print results    
	}
	numberofMonths = month;
	Payment = savePayment; //reinstate original payment amount  
}

void BoatLoan::calcRemainingMonths(){

	int month = 1; //intialize month counter
	int bal = getBalance(); //access private data
	int rate = getPirateRate(); //access private data
	int payFreq = getPaymentSchedule(); //access private data

	while (bal > 0) { //while boat loan has not been paid off

	    int interest = bal * rate/(1200/payFreq); //calculate interest (based on yearly frequency of Payment)
	    bal += interest; //add interest to principal
	    if (bal > Payment) { // if boatLoan is ongoing 
	    	bal -= Payment; //calculate new balance
	    	month+= payFreq; //increase month counter
	    } else { //calculate final Payment info
	    	int savePayment = Payment; //save value of payment
	        Payment = bal; //calculate final Payment
	        bal -= Payment; //bring balance to 0  
	        Payment = savePayment; //reinstate original payment amount
	    }
	}
	numberofMonths = month;
}

void BoatLoan::deposit(int Deposit){ //put money towards paying off loan (besides regular payment)

	int newBal = getBalance() - Deposit; //calculate new balance
	setBalance(newBal); //update to account
} 

void BoatLoan::print() { //print status of loan

	calcRemainingMonths(); //update remaining months

	cout << endl << boatName << "'s Boat Loan Status:" << endl << "==============" << endl;
	cout << "Current Amount Loaned: " << getBalance() << endl; 
	cout << "You only have " << numberofMonths << " months until your galleon is your own!" << endl;
	cout << "Please fill up your " << maxLootStorage << " sqft and use your " << numOfCannons << " cannons responsibily." << endl;
}

void BoatLoan::setPayment(int payment){

	cout << "in setPayment. setting payment to " << payment << "." << endl;
	int bal = getBalance();
	int rate = getPirateRate();
	int payFreq = getPaymentSchedule();

	if(payment > bal * (rate/payFreq*100)) Payment = payment; //check that payment is not too small
	else cout << "Error! Given payment must exceed interest." << endl; //output error message if too small

}

int BoatLoan::getMaxLootStorage(){
	return maxLootStorage;
}

void BoatLoan::setMaxLootStorage(int newLootMax){
	
	while(newLootMax <= 0){ //error checking
		cout << "Error! Maximum Loot Storage must be a postive quantity. Input new maximum: ";
		cin >> maxLootStorage;
	}
	//set loot max
	maxLootStorage = newLootMax;
}

int BoatLoan::getNumOfCannons(){
	return numOfCannons;
}

void BoatLoan::setNumOfCannons(int numCan){

	while(numCan <= 0){ //error checking - ship must have at least one cannon
		cout << "Error! Please input a valid (nonzero/positive) number of cannons: ";
		cin >> numCan;
	}
	
	numOfCannons = numCan; //set cannons
}

string BoatLoan::getBoatName(){
	return boatName;
}

void BoatLoan::setBoatName(string newName){
	boatName = newName; //set boat name
}

