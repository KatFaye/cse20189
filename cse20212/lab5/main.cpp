//main.cpp
//reads in an empty puzzle and stores it

#include "puzzle.h"

using namespace std;

int main(void) {

	int play = 0;

	Puzzle<int> exampleS("completepuzzle.txt");
	Puzzle<char> exampleW("completewordoku.txt");

	cout << "Display of example complete Sudoku puzzle: " << endl;
	exampleS.display();
	cout << "\n Display of example complete Wordoku puzzle: " << endl;
	exampleW.display();

	cout << "\n Play Sudoku (0) or Wordoku (1): " << endl;
	cin >> play;
	if(play) {
		Puzzle<char> testPuzzle("testwordoku.txt");
		testPuzzle.playGame();
	} else {
		Puzzle<int> testPuzzle("testinput.txt");
		testPuzzle.playGame();
	}
	


	return 0;
}