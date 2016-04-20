// jaccardSimilarity.cpp
// Author: Kat Herring
// Compute Jaccard similarity of two sets

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;
int main(void) {
	
	string docOne, docTwo, word;
	vector<string> doc1Set, doc2Set, intersect, unionSet;
	//get target docs
	cout << "Please enter two documents to estimate similarity." << endl;

	cin >> docOne >> docTwo;

	ifstream doc1(docOne.c_str());
	ifstream doc2(docTwo.c_str());
	
	if(doc1.is_open()) {
		while (doc1 >> word) {
			for (size_t i = 0; i<word.length(); i++) {
				if(ispunct(word[i]))
					word.erase(i--, 1);
				else
					word[i] = tolower(word[i]);
			}
			doc1Set.push_back(word);
		}
	}
	if(doc2.is_open()) {
		while (doc2 >> word) {
			for (size_t i = 0; i<word.length(); i++) {
				if(ispunct(word[i]))
					word.erase(i--, 1);
				else
					word[i] = tolower(word[i]);
			}
			doc2Set.push_back(word);
		}
	}

	set_intersection(doc1Set.begin(),doc1Set.end(),doc2Set.begin(),doc2Set.end(), inserter(intersect,intersect.begin()));
	set_union(doc1Set.begin(),doc1Set.end(),doc2Set.begin(),doc2Set.end(),inserter(unionSet, unionSet.begin()));

	cout << "The Jaccard Similarity is: " << (double)intersect.size()/unionSet.size() << endl;
	return 0;
}