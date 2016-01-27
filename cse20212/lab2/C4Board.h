//C4Board.hpp
//Author: Kat Herring
// header file for the C4Board class

#include "C4Col.h"
#include <iostream> 
#ifndef _C4Board_H_
#define _C4Board_H_


class C4Board {

	friend ostream &operator<<(ostream &, const C4Board &);
public:
	C4Board(); //default constructor
	~C4Board(); //deconstrutor
	void display(); //displays current board
	void displayIntro(); //displays intro to game
	void play(); //allows two players to play a game
	void setAI(); //choose if AI active in round

private: 
	int numCols; //number of columns in board
	C4Col board[7];
	int ai; //determines if ai player is active
	char userChar; //the symbol for each character's piece
	int winner(); //finds if a player has won
	int aiMove(); //ai player
};
#endif //_C4Board_H_