// guessLanguage.cpp
// Author: Kat Herring
// Guess the language that a given textfile is in (English or French)

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	vector<string> frenchWords;
	vector<string> englishWords;
	string word, inFile;
	int francais = 0, english = 0;
	//read in dictionaries of words
	ifstream frenchDict("french250.txt");
	ifstream englishDict("english.txt");

	if(frenchDict.is_open()) {
		while (frenchDict >> word) {
			frenchWords.push_back(word);
		}
	}
	if(englishDict.is_open()) {
		while (englishDict >> word) {
			englishWords.push_back(word);
		}
	}
	frenchDict.close();
	englishDict.close();

	//read in inputted text file
	cout << "Input text file to check. (English or French)" << endl;

	cin >> inFile;

	ifstream sampleText(inFile.c_str());

	if(sampleText.is_open()) {
		while(sampleText >> word) {
			//convert word to lowercase and remove punctuation
			for (size_t i = 0; i<word.length(); i++) {
				if(ispunct(word[i]))
					word.erase(i--, 1);
				else
					word[i] = tolower(word[i]);
			}
			//check if word is in French dictionary
			if(find(frenchWords.begin(), frenchWords.end(), word) != frenchWords.end()){
				//cout << word << endl;
				francais += 1;
			}
			//check if word is in English dictionary
			if(find(englishWords.begin(), englishWords.end(), word) != englishWords.end()){
				//cout << word << endl;
				english += 1;
			}
		}
	}
	//cout << english << " " << francais << endl;

	//use count to guess language
	if((english==0)&&(francais==0)) {
		cout << "Unable to guess language. No dictionary matches found." << endl;
	} else if(english>francais) {
		cout << "Predicted language is English. Certainty: " << 100*english/(english+francais) << "%" << endl;
	} else if(francais>english) {
		cout << "Predicted language is French. Certainty: " << 100*francais/(english+francais) << "%" << endl;
	} else {
		cout << "Unable to guess language." << endl;
	}
	return 0;

}