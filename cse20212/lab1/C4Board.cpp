//C4Board.cpp
// Author: Kat Herring
// Class for the Connect 4 board

#include "C4Board.h"
#include "C4Col.h"
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

C4Board::C4Board() { //default constructor
	numCols = 7;
	for(int i= 0;i<numCols;i++) {
		C4Col board[i]; //makes each row of type C4Col
	}
}
void C4Board::display() { //displays the current board
	for(int i=board[0].getMaxDiscs()-1;i>=0;i--) {
		for(int j=0;j<numCols;j++) {
			cout << " | " << board[j].getDisc(i);
			if(j==numCols-1) {
				cout << " |";
			}
		}
		cout << endl;
	}

}
void C4Board::displayIntro() { //displays intro to game
	cout << "Welcome to Connect 4: Text Edition!" << endl;
	for(int i=1;i<=numCols;i++) {
		cout << "  #" << i;
	}
	cout << endl;

}
void C4Board::play() { //play the game
	int colChoice = 0;
	int turn;

	displayIntro();

	while(colChoice!=-1) {
		display();

		turn = (turn%2) + 1;
		if(turn==1) {
			userChar = 'X';
		} else {
			userChar = 'O';
		}
		cout << "Player " << turn << " - Make move: ";
		cin >> colChoice;

		if(colChoice>0&&colChoice<numCols) { 
			board[colChoice].addDisc(userChar);
		} else {
			cin.clear();
			cin.ignore();
			cout << "Error: Invalid input! Skipping turn..." << endl;
		}
		cout << endl;
	}


}
