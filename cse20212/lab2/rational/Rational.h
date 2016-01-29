//Rational.h
//Author: Kat Herring
//class definition for Rational class for performing arithmetic with fractions

#include <iostream>
#include <iomanip>

class Rational {
public:
	Rational(int newNum = 1, int newDemon = 1); //default Rational is one
	~Rational();

private: 
	int numerator; //numerator of Rational num
	int denominator; //denominator of Rational num
};