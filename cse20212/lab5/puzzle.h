//puzzle.h
//Class definition for templated Sudoku game
//Author: Kat Herring

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

template <class T>
class Puzzle {

public:
	Puzzle<T>(string);
	void display(); //displays board
	void playGame(); //try to complete puzzle
	void insertNum(int, int, T); //inserts a number into a blank space on the board
	int checkWin(); //checks if board has been completed successfully
	bool validMove(int, int, T); //checks if given move is valid
private:
	vector<vector<T> > board; //sudoku board
	string fileName; //default name for input
	
};
template<class T>
Puzzle<T>::Puzzle(string fileName = "testinput.txt") { //default constructor
	fstream infile;
	vector <T> newRow(9);
	infile.open(fileName.c_str(), ios::in);
	int row=0;

	T a;
	if(infile.is_open()) {
		

		while(infile.good()) {
			board.push_back(newRow);
			for (int col=0; col<9; col++) {
				infile >> board[row][col];
			}

			row++; //current row in
		}
	}

	infile.close();
} 
template<class T>
void Puzzle<T>::display() {
	cout << "   "; //formatting to make cols line up
	for(int k=1;k<10;k++) {
		cout << setw(4) << k;
	}
	cout << endl;
	int l = 1;
	cout << "  _________________________________________" << endl << "1 || "; //first row topper

	for (int i=0; i<9; i++) {
		l++;
		for (int j=0; j<9; j++) {

			if(board[i][j]==0) //empty space
				cout << "_";
			else {
				cout << board[i][j];
			}

			if((j+1)%3==0) {
				cout << " || ";
			} else {
				cout << " | ";
			}
		}
		if((i+1)%3==0&&i<8) { // double line borders for 3x3 boxes
			cout << endl << "  _________________________________________" << endl << "  _________________________________________" << endl;
		} else {
			cout << endl << "  _________________________________________" << endl;
		}
		
		if(i<8) {
			cout << l;
			cout << " || ";
		}	
	}
}
template<class T>
void Puzzle<T>::playGame() { //player interface
	cout << "Welcome to Sudoku! \n Finish the board to win! \n Enter row, col, entry to complete (i.e. 1 1 1 to place 1 in the top-left corner)" <<endl;
	display();
	
	int hasWon = checkWin(), col, row, quit = 0;
	T entry;
	while(!hasWon&&!quit) {
		cin >> row;
		if(row==0) {
			quit = 1;
		} else {
			cin >> col >> entry;
			insertNum(row, col, entry);
			hasWon = checkWin();
			display();
			if(!hasWon) {
				cout << "(row, col, entry, or 0 to quit): ";
			}
		}
	}
	if(hasWon) {
		cout << "Congratulations! You win!" << endl;
	}
}
template<class T>
void Puzzle<T>::insertNum(int row, int col, T entry){ //inserts a number into a blank space on the board

	bool isValid = validMove(row-1, col-1, entry); //checks if given move is valid
	//cout << isValid << "is valid" << endl;
	if (isValid){ //space is empty
		board[row-1][col-1] = entry;
	} else {
		cout << "You cannot place an entry there!" << endl;
	}

	}
template<class T>
int Puzzle<T>::checkWin() { //checks if board has been completed successfully

	for(int row=0;row<9; row++) {
		for(int col=0;col<9;col++) {
			if(board[row][col]==0) {
				return 0; //any blank spaces means player has not won
			} else {
				for(int i=0; i<9; i++) {
					if(board[row][col]==board[i][col]&&i!=row) { //two of same number in col
						return 0;
					} else if(board[row][col]==board[row][i]&&i!=col) { //two of same number in row
						return 0;
					}
				}
			}
		}
	}
	for(int r=0;r<9;r+=3) { //check for unique minigrid (0-2; 3-5; 6-8)
		for(int c=0;c<9;c+=3) {
			for(int j=r;j<r+3;j++) {
				for(int k=c;k<c+3;k++) {
					if(board[r][c]==board[j][k]&&(j!=r||c!=k)) {
						return 0;
					}
				}
			}
		}
	}
	return 1; //has won
}
template<class T> 
bool Puzzle<T>::validMove(int row, int col, T entry) {
	if(board[row][col]!=0&&board[row][col]!='0') {
		cout << "There is already an entry there. " << endl;
		return 0; //already a number there
	}
	for(int i=0;i<9;i++) {
		if(entry==board[i][col]&& (i!=row)) { //proposed entry is in col
			cout << "There is already an entry of that value in this col." << endl;
			return 0;
			
		} else if(entry==board[row][i]&&i!=col) { //proposed entry is in row
			cout << "There is already an entry of that value in this row." << endl;
			return 0;
		}
	}
	int r, c;
	if(row<3) {
		r=0;
	} else if(row<6) {
		r=3;
	} else if(row<9) {
		r=6;
	}
	if(col<3) {
		c=0;
	} else if(col<6) {
		c=3;
	} else if (col<9) {
		c=6;
	}
	//which minigrid in
	for(int j=r;j<r+3;j++) {
		for(int k=c;k<c+3;k++) {
			if(entry==board[j][k]&&board[j][k]!=0) {
				cout << "There is already an entry of that value in the minigrid." << endl;
				return 0;
			}
		}
	}
	return 1; //valid move
}