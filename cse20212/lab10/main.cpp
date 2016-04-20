//main.cpp
//Display of puzzle solver
//Author: Kat Herring

#include "puzzle.h"
#include <string>

using namespace std;

int main(void) {
	
	//cout << "Test";

	string fileName = "testinput.txt";

	Puzzle testPuzzle(fileName);

	//cout << "\nSolution to Easy Puzzle: " << endl;
	//testPuzzle.displaySol();

	return 0;
} 