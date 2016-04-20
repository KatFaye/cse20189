// dataProcess.cpp
// Author: Kat Herring
// detect/process similar documents

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <map>

using namespace std;

int main(void) {

	map<string, int> wordCounts;

	string f1, f2, line, f1Out, f2Out, count, word;
	//regex punc("?![a-zA-Z0-9]*", regex_constants::icase);
	cout << "Input two plain-text files (do not include .txt extension)" << endl;
	cin >> f1 >> f2;

	f1Out = "tempOut.txt";
	f2Out =  "uniqOut.txt";
	count = "wordOut.txt";
	f1 = f1 + ".txt";
	f2 = f2 + ".txt";


	ifstream inFile(f1.c_str());
	ifstream inFile2(f2.c_str());
	ofstream outFile(f1Out.c_str());


	//process files

	if(inFile.is_open()) {
		while(inFile.good()) {
			getline(inFile, line);
			//remove punctuation
			for (size_t i = 0; i<line.length(); i++) {
				if(ispunct(line[i]))
					line.erase(i--, 1);
				else
					line[i] = tolower(line[i]);

				
			}
			outFile << line;
		}
	} else {
		cout << "Unable to open " << f1 << "!" << endl;
	}

	//add blank space between files
	outFile << ' ';

	if(inFile2.is_open()) {
		while(inFile2.good()) {
			getline(inFile2, line);
			//remove punctuation
			for (size_t i = 0; i<line.length(); i++) {
				if(ispunct(line[i]))
					line.erase(i--, 1);
				else
					line[i] = tolower(line[i]);
			}
			outFile << line;
		}
	} else {
		cout << "Unable to open" << f2 << "!" << endl;
	}
	outFile.close();
	inFile.close();
	inFile2.close();

	ifstream tempIn(f1Out.c_str());
	ofstream outFile2(f2Out.c_str());
	ofstream fCount(count.c_str());

	//use temp file to create array
	if(tempIn.is_open()) {
		while(tempIn >> word) {
			wordCounts[word]++;
			//cout << word;
		}
	}
	// saves number of unique words to uniqOut.
	outFile2 << wordCounts.size() << endl;

	// save word and times used to wordOut
	for(auto const &ent1 : wordCounts) {
		fCount << ent1.first << ": " << ent1.second << endl;
	}
	//close all files

	outFile2.close();
	fCount.close();
	tempIn.close();

	//cleans up temporary file
	if( remove(f1Out.c_str()) != 0) {
		perror( "Error deleting tempOut.txt");
	}
	return 0;
}