//C4Col.cpp
//function definitions for C4Col class
//Author: Kat Herring

#include <iostream>
#include <iomanip>
#include <cctype>
#include "C4Col.h" //includes class definition defined in C4Col.hpp

using namespace std;

//C4Col constructor initializes current discs to zero, maximum disks to six
//initializes character array with ' ' characters

C4Col::C4Col() {
	int i;

	disksInCol = 0; //current disks in col
	maxDisksAllowed = 6; //how many disks per col 
	colItems = new char [6];
	for(i=0;i<=5;i++) { // set character array to ' '
		colItems[i] = ' ';
	}
}
C4Col::~C4Col() {
	delete[] colItems;
}
int C4Col::isFull() { //determines if column is full
	if(disksInCol>=6) {
		return 1; //column is full
	} else {
		return 0; //column is not full
	}
}
char C4Col::getDisc(int discLocation) { //returns requested element of char array
	if(discLocation>=0&&discLocation<=5) { //valid input
		return colItems[discLocation];
	}
	else {
		cout << "Error: Not a valid location on board!" << endl;
	}
}
int C4Col::getMaxDiscs() { //returns max number of discs
	return maxDisksAllowed;
}
void C4Col::addDisc(char userChar) { //adds character representing disk to next open slot
	if(isFull()) {
		cout << "Error: The column you are attempting to place a disk in is full!" << endl;
	} else {
		colItems[disksInCol] = userChar;
		disksInCol++;
	}
}