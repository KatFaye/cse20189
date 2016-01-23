//C4Col.hpp
//Class definition for C4Col
//Author: Kat Herring

#ifndef _C4COL_H_
#define _C4COL_H_

class C4Col {
public:
	C4Col();
	int isFull(); //determines if column is full
	char getDisc(int); //returns requested element of char array
	int getMaxDiscs(); //returns max number of discs
	void addDisc(char); //adds character representing disk to next open slot

private:
	int disksInCol;
	int maxDisksAllowed;
	char colItems[5]; //characters representing no item, player 1 & 2
};

#endif //_C4COL_H_