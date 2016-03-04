//main.cpp
//Display of puzzle solver
//Author: Kat Herring

#include "puzzle.h"
#include <vector> 

using namespace std;

int main(void) {
	
	Puzzle<int> testPuzzle("testinput.txt");

	cout << "Blank Easy Puzzle: " << endl;
	testPuzzle.display(0);

	cout << "\nSolution to Easy Puzzle: " << endl;
	testPuzzle.displaySol();

	//Puzzle<int> mediumPuzzle("medium.txt");
	//cout << "Blank Medium Puzzle:" << endl;
	//mediumPuzzle.display(0);

	//cout << "Changes to Vector" << endl;

	//testPuzzle.showSolution();
	return 0;
} 