//C4Board.cpp
// Author: Kat Herring
// Class for the Connect 4 board

#include "C4Board.h"
#include "C4Col.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

using namespace std;

C4Board::C4Board() { //default constructor
	numCols = 7;
	board = new C4Col [7];
	ai = 0;

	for(int i= 0;i<numCols;i++) {
		C4Col board[i]; //makes each row of type C4Col
	}
}
C4Board::~C4Board() {
	delete[] board;
}
int C4Board::aiMove() { //artificial player
	return (rand()%numCols); //returns random position

}
void C4Board::display() { //displays the current board
	for(int i=1;i<=numCols;i++) {
		cout << "  #" << i;
	}
	cout << endl;
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

}
void C4Board::play() { //play the game
	int colChoice = 0, hasWon = 0;
	int turn;

	displayIntro();
	setAI();
	display();

	while(colChoice!=-1&&hasWon==0) {

		turn = (turn%2) + 1;
		if(turn==1) {
			userChar = 'X';
			cout << "Player " << turn << " - Make move: ";
			cin >> colChoice;
		} else {
			if(ai) {
				colChoice = aiMove();
			} else {
				cout << "Player " << turn << " - Make move: ";
				cin >> colChoice;
			}
			userChar = 'O';
		}
		if(colChoice>0&&colChoice<=numCols) { 
			board[colChoice-1].addDisc(userChar);
			display();
		} else if(colChoice==-1) {
			cout << "Thank you for playing!" << endl;

		} else {
			cin.clear();
			cin.ignore();
			cout << "Error: Invalid input! Skipping turn..." << endl;
		}
		cout << endl;
		hasWon = winner();
	}
	if(hasWon) {

		cout << "Congratulations Player " << hasWon << ", you win!" << endl;
	}
}
void C4Board::setAI() { //determines if AI is active in game
	cout << "Play with AI? (1- yes; 0- no)" << endl;
	cin >> ai;
	if(ai!=1&&ai!=0) {
		cout << "Error: invalid input. Starting game without AI." << endl;
	}
}
int C4Board::winner() { //determines if a player has won
	int playerOnePieces = 0;
	int playerTwoPieces = 0;

	for(int i=0;i<numCols;i++) { //check for vertical victory
		for(int j=0;j<(board[i].getMaxDiscs());j++) {
			if(board[i].getDisc(j)=='X') { //player 1 piece
				playerOnePieces++;
			} else if(board[i].getDisc(j)=='O') { //player 2 piece
				playerTwoPieces++;
			} else {
				playerOnePieces = 0; //resets count of pieces in row
				playerTwoPieces = 0; //resets count of pieces in row
			}
			if(playerOnePieces==4) {
				return 1; //player 1 has won
			} else if(playerTwoPieces==4) {
				return 2; //player 2 has won
			} 
		}
	}
	for(int j=0;j<(board[0].getMaxDiscs());j++) { //horizontal victory
		for(int i=0;i<numCols;i++) {
			if(board[i].getDisc(j)=='X') { //player 1 piece
				playerOnePieces++;
			} else if(board[i].getDisc(j)=='O') { //player 2 piece
				playerTwoPieces++;
			} else {
				playerOnePieces = 0; //resets count of pieces in row
				playerTwoPieces = 0; //resets count of pieces in row
			}
			if(playerOnePieces==4) {
				return 1; //player 1 has won
			} else if(playerTwoPieces==4) {
				return 2; //player 2 has won
			} 
		}
	}
	for(int j=0;j<(board[0].getMaxDiscs());j++) { //diagonal bottom-left to top-right victory
		for(int i=j;i<numCols;i++) {
			if(board[i].getDisc(j)=='X') { //player 1 piece
				playerOnePieces++;
				break;
			} else if(board[i].getDisc(j)=='O') { //player 2 piece
				playerTwoPieces++;
				break;
			} 
			if(playerOnePieces==4) {
				return 1; //player 1 has won
			} else if(playerTwoPieces==4) {
				return 2; //player 2 has won
			} 
		}
	}
	playerOnePieces = 0;
	playerTwoPieces = 0;

	for(int j=0;j<(board[0].getMaxDiscs());j++) { //diagonal bottom-left to top-right victory
		for(int i=numCols-1;i>=0;i--) {
			if(board[i].getDisc(j)=='X') { //player 1 piece
				playerOnePieces++;
				break;
			} else if(board[i].getDisc(j)=='O') { //player 2 piece
				playerTwoPieces++;
				break;
			} 
			if(playerOnePieces==4) {
				return 1; //player 1 has won
			} else if(playerTwoPieces==4) {
				return 2; //player 2 has won
			} 
		}
	}

	return 0; //no winner detected
}
