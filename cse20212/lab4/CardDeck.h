//CardDeck.h
// Author: Kat Herring
// Class definition for CardDeck

#include <iostream>
#include <deque>

using namespace std;

#ifndef _CARDDECK_H_
#define _CARDDECK_H_

class CardDeck {
public:
	CardDeck(int n = 52);
	int getSize(); //returns size of current deck
	void shuffle(); //shuffles deck
	int inOrder(); //checks if elements in non-decreasing order
private:
	deque<int> deck;

};

#endif //_CARDDECK_H_
