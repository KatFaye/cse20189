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

#ifndef _PUZZLE_H_
#define _PUZZLE_H_

template <class T>
class Puzzle {

public:
	Puzzle<T>(string);
	void display(bool); //displays board
	void displaySol();
	int checkSolver(); //checks if board solution
	void showSolution(); //display solution
	void playGame(); //try to complete puzzle
	void insertNum(int, int, T); //inserts a number into a blank space on the board
	int checkWin(bool); //checks if board has been completed successfully
	bool validMove(int, int, T); //checks if given move is valid
private:
	void solveBoard();
	vector< vector<T> > board; //sudoku board
	vector< vector<T> > solution;
	vector< vector <vector<T> > > solver;
	
};
template<class T>
Puzzle<T>::Puzzle(string fileName) { //default constructor
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

	solver.push_back(board);

	infile.close();

	for(int i=1;i<10;i++) {
		solver.push_back(board);
		for(int j=0;j<9;j++) {
			for(int k=0;k<9;k++) {
				if(solver[0][j][k]!=0) {
					solver[i][j][k] = 0;
				} else {
					solver[i][j][k] = i;
				}
			}
		}
	}
	solveBoard();
} 
template<class T>
void Puzzle<T>::display(bool sol) {

	vector< vector<T> > checking = board;
	if(sol) {
		vector< vector<T> > checking = solution;
	}

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

			if(checking[i][j]==0) //empty space
				cout << "_";
			else {
				cout << checking[i][j];
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
	display(0);
	
	int hasWon = checkWin(0), col, row, quit = 0;
	T entry;
	while(!hasWon&&!quit) {
		cin >> row;
		if(row==0) {
			quit = 1;
		} else {
			cin >> col >> entry;
			insertNum(row, col, entry);
			hasWon = checkWin();
			display(0);
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
int Puzzle<T>::checkWin(bool sol) { //checks if board has been completed successfully

	vector< vector<T> > checking = board;
	if(sol) {
		checking = solution;
	}

	for(int row=0;row<9; row++) {
		for(int col=0;col<9;col++) {
			if(checking[row][col]==0) {
				return 0; //any blank spaces means player has not won
			} else {
				for(int i=0; i<9; i++) {
					if(checking[row][col]==checking[i][col]&&i!=row) { //two of same number in col
						return 0;
					} else if(checking[row][col]==checking[row][i]&&i!=col) { //two of same number in row
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
					if(checking[r][c]==checking[j][k]&&(j!=r||c!=k)) {
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
template<class T>
void Puzzle<T>::showSolution() {
	for(int poss=0;poss<10;poss++) {
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

				if(solver[poss][i][j]==0) //empty space
					cout << "_";
				else {
					cout << solver[poss][i][j];
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
}
template<class T>
void Puzzle<T>::solveBoard() {

	int hiddenSingle;
	int singleVal = 0;
	int pushVal;
	int r, c, val;
	int testing =0;
	while(!checkSolver()) {
		for(int j=0;j<9;j++) {
			for(int k=0;k<9;k++) {
				if(solver[0][j][k]!=0) { 
					val = solver[0][j][k]; //check for singles
					for(int i=0;i<9;i++){
						solver[val][j][i] = 0; // set row to zero
						solver[val][i][k] = 0; //set col to zero
					}
					if(j<3) {
						r=0;
					} else if(j<6) {
						r=3;
					} else if(j<9) {
						r=6;
					}
					if(k<3) {
						c=0;
					} else if(k<6) {
						c=3;
					} else if (k<9) {
						c=6;
					}
					//which minigrid in
					for(int mini=r;mini<r+3;mini++) {
						for(int grid=c;grid<c+3;grid++) {
							solver[val][mini][grid] = 0;
						}
					}
				} 
			}
		}
		

		//check for new values to push down
		for(int j=0;j<9;j++) {
			for(int k=0;k<9;k++) {
				singleVal=0;
				hiddenSingle=0;
				for(int check=1;check<10;check++) {
					if(solver[check][j][k]!=0) {
						pushVal = solver[check][j][k];
						singleVal++;
						for(int hidden; hidden<9; hidden++) {
							if(solver[check][hidden][k]!=0) {
								hiddenSingle++;
							}
						}

					}
				}
				if(singleVal==1||hiddenSingle==1) { //only possibility in location
					solver[0][j][k] = pushVal;
				} 
			}
		}

	} //endwhile

	//showSolution();
}
template<class T>
int Puzzle<T>::checkSolver() {
	for(int row=0;row<9; row++) {
		for(int col=0;col<9;col++) {
			if(solver[0][row][col]==0) {
				return 0; //any blank spaces means player has not won
			} else {
				for(int i=0; i<9; i++) {
					if(solver[0][row][col]==solver[0][i][col]&&i!=row) { //two of same number in col
						return 0;
					} else if(solver[0][row][col]==solver[0][row][i]&&i!=col) { //two of same number in row
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
					if(solver[0][r][c]==solver[0][j][k]&&(j!=r||c!=k)) {
						return 0;
					}
				}
			}
		}
	}
return 1; //has won
}
template<class T>
void Puzzle<T>::displaySol() {

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

			if(solver[0][i][j]==0) //empty space
				cout << "_";
			else {
				cout << solver[0][i][j];
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
#endif //_PUZZLE_H_