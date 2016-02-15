//main.cpp
//Author: Kat Herring
//Driver function for CardDeck testing

#include "CardDeck.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

int main(void) {

	int tests[3] = {0};
	vector<CardDeck> monkeySort(1, CardDeck(7));
	monkeySort.push_back(CardDeck(8));
	monkeySort.push_back(CardDeck(9));
	
	//seed random number
	srand(time(NULL));

	//part II on lab 
	CardDeck testDeck(10);

	testDeck.inOrder();

	cout << "Displaying in reverse..." << endl;
	testDeck.printReverse();

	cout << "\nDisplaying in order..." << endl << testDeck;

	cout << "\nShuffling..." << endl;

	testDeck.shuffle();

	cout << testDeck << endl;

	//part III, 1)

	cout << "Monkey Sort \n==========" << endl;
	for(int i=0;i<3;i++) { //sorts each monkeySort object three times
		for(int j=0;j<3;j++) {
		monkeySort[i].shuffle();
		tests[j] = monkeySort[i].monkeySort();
		}		
	cout << "Number of shuffles required to resort " << i+7 << " cards: "; 
	cout << tests[0] << ", " << tests[1] << ", " << tests[2] << endl;
	}

	return 0;
}