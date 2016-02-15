//puzzle.h
//Class definition for templated Sudoku game
//Author: Kat Herring

#include <vector>
#include <iostream>

template <typename T>
class Puzzle {
public:
	Puzzle();
private:
	vector<vector<T> > board; //sudoku board
};
template<typename T>
Puzzle<T>::Puzzle() { //default constructor


}