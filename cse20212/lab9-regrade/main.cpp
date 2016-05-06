//main.cpp
//Display of NDvector
//Author: Kat Herring

#include "ndvector.h"
#include "CardDeck.h"

using namespace std;

int main(void) {

	NDVector<int> vector(2);

	cout << "Size of vector: " << vector.size() << endl;
	cout << "Pushing items into NDVector..." << endl;

	for(int i = 0; i < 5; i++) {
		vector.push_back(i);
		cout << "Vector[" << i << "]: " << vector[i] << endl;
	}
	cout << "Creating new NDVector with copy constructor..." << endl;

	NDVector<int> newVector = vector;
	cout << "Value of newVector[3]: " << newVector[3] << endl << endl;

	cout << "Back of vector: " << vector.back() << endl;

	cout << "Popping value from NDVector..." << endl;
	vector.pop_back();

	for(int i = 0; i < vector.size(); i++) {
		cout << "Vector [" << i << "]: " << vector[i] << endl;
	}
	cout << "Clearing vector..." << endl;
	vector.clear();
	cout << "Number of values in vector after clear: " << vector.size() << endl;
	
	cout << endl;
	cout << "CardDeck Functionality" << endl;
	CardDeck testDeck;

	cout << testDeck << endl;
	cout << "Shuffling deck..." << endl;
	testDeck.shuffle();

	cout << testDeck << endl;

	return 0;
} 