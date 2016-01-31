//Rational.h
//Author: Kat Herring
//class definition for Rational class for performing arithmetic with fractions

#include <iostream>
#include <iomanip>

using std::ostream;
using std::istream;

class Rational {
	friend ostream & operator<<( ostream &, Rational &);
	friend istream & operator>>( istream &, Rational &);

public:
	Rational(int newNum = 1, int newDemon = 1); //default Rational is one
	int simplifyRational(); //simplifies Rational fraction
	void setRational(); //sets value of rational
	int getRational(); //dispaly value of rational
	int getNumerator(); //display numerator
	int getDenominator();
	void setNumerator(int);
	void setDenominator(int);
	//overloaded arithmetic operators
	Rational operator*(Rational r);
	Rational operator+(Rational r);
	Rational operator-(Rational r);
	Rational operator/(Rational r);
	//raises an object to a give power
	Rational operator^(int power);
private: 
	int findGCD(); //helper function finds GCD
	int numerator; //numerator of Rational num
	int denominator; //denominator of Rational num
	int GCD; //GCD of numerator and denominators; should be 1
};