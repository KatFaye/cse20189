//C4Board.hpp
//Author: Kat Herring
// header file for the C4Board class

#include "C4Col.h"
#include <iostream> 
#ifndef _C4Board_H_
#define _C4Board_H_

using std::ostream;
using std::istream;

class C4Board {

	friend ostream & operator<<( ostream &, C4Board &);
	friend istream & operator>>( istream &, C4Board &);

public:
	C4Board(); //default constructor
	~C4Board(); //deconstrutor-1
	void displayIntro(); //displays intro to game
	void play(); //allows two players to play a game
	void setAI(); //choose if AI active in round
	int getCols(); //get number of columns

private: 
	int numCols; //number of columns in board
	C4Col board[7];
	int ai; //determines if ai player is active
	char userChar; //the symbol for each character's piece
	int winner(); //finds if a player has won
	int aiMove(); //ai player
};
#endif //_C4Board_H_