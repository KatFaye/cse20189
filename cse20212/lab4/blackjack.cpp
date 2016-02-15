//blackjack.cpp
//Author: Kat Herring
//Play a game of blackjack using the CardDeck class

#include "CardDeck.h"

int main(void) {

	//seed random number
	srand(time(NULL));

	CardDeck blackjack;

	blackjack.playBlackjack();

	//cout << blackjack;

	return 0;
}