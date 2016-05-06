//CardDeck.cpp
// Author: Kat Herring
//implementation for CardDeck

#include "CardDeck.h"

using namespace std;

CardDeck::CardDeck(int n) {
	for(int i=0; i<n; i++) {
		deck.push_back(i);
	}

	dealerWins = userWins = turns = aiMode = 0;
	aiMoney = 100; // AI gets $100 bank
	bank = 10000; //bank essentially has endless money
	srand( time(NULL) );
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
	return 1; //non-decreasing
}
void CardDeck::shuffle() { //shuffles deck
	//random_shuffle(deck.begin(), deck.end());
	int temp, temp2, num;

	for(int i = 1; i<deck.size();i++) {
		num = (int)rand()%i;
		//swap numbers
		temp = deck[i];
		deck.setVal(i, deck[num]);
		deck.setVal(num, temp);
	}

}
NDVector<int> CardDeck::getDeck() {
	return deck;
}
int CardDeck::monkeySort() {

	//randomly shuffles cards until they are in order
	int shuffles = 0;

	while(!inOrder()) {
		shuffle();
		shuffles++; //number of attempts to sort
	}

	return shuffles;
}
void CardDeck::playBlackjack() {
// begins a game of blackjack
bool play = 1, hit;

cout << "Blackjack: Get as close to 21 as you can!" << endl;
shuffle(); //ensures deck shuffled before game begins
cout << "AI vs. Dealer mode? Yes (1) | No (0)" << endl;
cin >> aiMode;

while(play&&aiMoney>0) { //ai will keep playing until he runs out of money
	cout << "New Game\n========\n" << endl;
	turns = 0;
	if(deck.size()<15) {
		deck.clear();
		for(int i=0; i<52; i++) {
			deck.push_back(i);
		}
		cout << "Shuffling new deck..." << endl;
		shuffle();
	} 
	dealerScore = userScore = 0;
	hit = 1; //sets default value for hit
	while(hit&&userScore<=21) {
		hit = deal();
	}
	cout << "Dealer final total: " << dealerScore << "." << endl;
	findWinner();

	cout << "Dealer Wins: " << dealerWins << " | Player Wins: " << userWins << endl;
	if(!aiMode) {
		cout << "Would you like to play again? 1 - yes 0 - no" << endl;
		cin >> play;
	}
}

}
bool CardDeck::deal() {
	//deal cards for blackjack
	int hit = 1;
	int card = deck.back()%4;
	turns++;

	//convert card to equivalent value
	if(dealerScore<17) {
		card = convertCard(card);
		deck.pop_back();
		dealerScore += card;
		if(turns==1) {
			cout << "Dealer current visible total: " << dealerScore << endl;
			visibleScore = dealerScore;
		}
		while(dealerScore<17) {
			card = convertCard(card);
			deck.pop_back();
			dealerScore += card;
		}
	}
	card = deck.back()%4;
	card = convertCard(card);
	userScore += card;
	deck.pop_back();
	if(turns>1&&userScore<=21) {
		cout << "Your current total is " << userScore << "." << endl;
		if(aiMode) {
			hit = aiPlay();
		} else {
			cout << "Hit (1) or Stand (0)?" << endl;
			cin >> hit;
		}
	}
	return hit;
}
int CardDeck::convertCard(int card) {
//converts card to appropriate 2-11 value

	if(card==0) { // card is ace
		card = 11;
	} else if(card>8) {
		card = 10;
	} else {
		card++;
	}
	return card;
}
void CardDeck::findWinner() {

	int winner = 0; //0 = dealer win, 1 = user win
	if(dealerScore>21||userScore>21) {
		string result = (userScore>21) ? "Player": "Dealer";
		winner = (userScore>21) ? 1 : 0; //tie goes to the dealer
		cout << result << " bust!" <<endl;
	} else {
		winner = (dealerScore>=userScore) ? 0 : 1; //checks who won, tie goes to the dealer
	}
	string win = winner ? "Player" : "Dealer";
	cout << win << " has won the round!" << endl;

	if(aiMode) {
		if(winner) {
			aiMoney += 5;
			bank -= 5;
		} else {
			aiMoney -= 5;
			bank += 5;
		}
		cout << "AI cash on hand: $" << aiMoney << endl;
	}
	if(winner) {
		userWins++;
	} else {
		dealerWins++;
	}

}
int CardDeck::aiPlay() {
	if(visibleScore>3&&visibleScore<7) { //assumes dealer will bust
		return 0;
	} else if(userScore<16) { //always hit if score below 16
		return 1;
	}
	return 0; //stay in all other cases
}
void CardDeck::print() {
	for(int i=0;i<deck.size();i++) {
		cout << deck[i] << ", ";
	}
}
ostream &operator<<(ostream &output, CardDeck &c ) {
//overloaded << will display elements separated with ',', ending with endl

c.print();

cout << endl;

return output;
}