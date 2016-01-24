//main.cpp
//main program for Connect Four Game
//Author: Kat Herring

/* This is a connect four game which uses the classes "C4Col" and "C4Board" to create a function game of 
Connect Four. The game can be played in multiplayer mode with two players, or an AI which randomly selects a column 
to play in can be played against. The game ends when a play gets four in a row, or enters -1 to quit!
 */

#include "C4Col.h"
#include "C4Board.h"

using namespace std;

int main(void) {

	C4Board game; //creates default object of type C4Board
	game.play();


	return 0;
}