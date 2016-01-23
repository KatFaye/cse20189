//C4Board.hpp
//Author: Kat Herring
// header file for the C4Board class

#include "C4Col.h"

#ifndef _C4Board_H_
#define _C4Board_H_

class C4Board {
public:
	C4Board(); //default constructor
	void display(); //displays current board
	void displayIntro(); //displays intro to game
	void play(); //allows two players to play a game

private: 
	int numCols; //number of columns in board
	C4Col board[10];
	char userChar; //the symbol for each character's piece
};
#endif //_C4Board_H_