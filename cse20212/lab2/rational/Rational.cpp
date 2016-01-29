//Rational.cpp
// Author: Kat Herring
// Member function definitions for Rational class

#include "Rational.h"
#include <iostream>

using namespace std;

Rational::Rational(int newNum, int newDenom) {
	if(newDenom!=0) {
		denominator = newDenom;
	} else {
		cout << "Error: Denominator cannot be zero" << endl;
	}
	numerator = newNum;
}

