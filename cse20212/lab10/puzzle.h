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
#include <set>
#include <algorithm>

using namespace std;

#ifndef _PUZZLE_H_
#define _PUZZLE_H_

class Puzzle {

public:
	Puzzle(string);
	//void display(bool); //displays board
	void displaySol();
	int checkSolver(); //checks if board solution
	//void showSolution(); //display solution
	//void playGame(); //try to complete puzzle
	//void insertNum(int, int, T); //inserts a number into a blank space on the board
	int checkWin(bool); //checks if board has been completed successfully
	//bool validMove(int, int, T); //checks if given move is valid
private:
	void solveBoard();
	vector< vector<int> > board; //sudoku board
	vector< vector<int> > solution;
	vector< vector <set<int> > > solver;
	
};
Puzzle::Puzzle(string fileName) { //default constructor
	cout << "fileName";
	vector<int>  newRow(9,0);
	for(int i=0;i<9;i++)
		board.push_back(newRow);
	
	ifstream infile;
	
	infile.open(fileName.c_str());

	set<int> tempSet,tempVal;
	for(int i=1;i<10;i++)
		tempSet.insert(i);

	vector<set<int> > tempVec; //(9, set);
 
 	cout << "Test";
	if(infile.is_open()) {
		

		while(infile.good()) {
			for (int col=0; col<9; col++) {
				int tempInt;
				infile >> tempInt;
				if(tempInt!=0){
					tempVal.insert(tempInt);
					set_intersection(tempVal.begin(),tempVal.end(),tempSet.begin(),tempSet.end(),inserter(tempVec[col],tempVec[col].begin()));
				}
				else{
					tempVec.push_back(tempSet);
				}
				
			}
			solver.push_back(tempVec);
			
		}
	}
	infile.close();
	solveBoard();
}
void Puzzle::solveBoard() {

	//int pushVal;
	int r, c, val;
	while(!checkSolver()) {
		for(int j=0;j<9;j++) {
			for(int k=0;k<9;k++) {
				if(board[j][k]!=0) { 
					val = board[j][k]; //check for singles
					for(int i=0;i<9;i++){
						solver[j][i].erase(val); // set row to zero
						solver[i][k].erase(val); //set col to zero
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
							solver[mini][grid].erase(val);
						}
					}
				} 
			}
		}
		

		//check for new values to push down
		for(int j=0;j<9;j++) {
			for(int k=0;k<9;k++) {
				if(solver[j][k].size()==1) {
					board[j][k] = *solver[j][k].begin();
				}

			}
		}

	} //endwhile

	//showSolution();
}
int Puzzle::checkSolver() {
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
void Puzzle::displaySol() {

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
#endif //_PUZZLE_H_
