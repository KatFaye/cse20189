//CardDeck.cpp
// Author: Kat Herring
//implementation for CardDeck

#include "CardDeck.h"
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

CardDeck::CardDeck(int n) {
	for(int i=0; i<n; i++) {
		deck.push_back(i);
	}
}
int CardDeck::getSize() {
	return deck.size(); //returns size of deck
}
int CardDeck::inOrder() {
	for(int i=0; i<getSize()-1; i++) {// run through deck
		if(deck[i]>deck[i+1]) {
			return 0;
		}
	}
	return 1;
}
void CardDeck::shuffle() { //shuffles deck
	random_shuffle(deck.begin(), deck.end());
}