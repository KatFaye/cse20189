//Rational.cpp
// Author: Kat Herring
// Member function definitions for Rational class

#include "Rational.h"
#include <iostream>
#include <cmath>

using namespace std;

Rational::Rational(int newNum, int newDenom) {
	if(newDenom!=0) {
		denominator = newDenom;
	} else {
		cout << "Error: Denominator cannot be zero; setting denominator to one." << endl;
		denominator = 1;
	}
	numerator = newNum;

	simplifyRational();
}
int Rational::findGCD() {
    int GCD, larger, smaller, quotient, r, temp;
    int  gcdNum, gcdDenom;

    //remove negatives to compute GCD
    gcdNum = abs(numerator);
    gcdDenom = abs(denominator);

    //check which is larger
    if (gcdNum > gcdDenom) {
            larger = gcdNum;
            smaller = gcdDenom;
    } else {
            larger = gcdDenom;
            smaller = gcdNum;
    }

    //Use algorithm: larger = smaller * quotient(x, y) + remainder to find GCD
    quotient = larger/smaller;
    r = larger%smaller;

    //use old divisor as new dividend and remainder as new divisor
    while(r!=0) {
            quotient = smaller/r;
            temp = smaller;
            smaller = r;
            r = temp%r;
    }

    //return results
    GCD = smaller;
    return GCD;

}
int Rational::simplifyRational() {
//simplifies the rational number

	while(GCD!=1) { //test to ensure rational fully simplified
		GCD = findGCD();
		numerator = numerator/GCD;
		denominator = denominator/GCD;
	}
	return 0;
}
ostream &operator<<(ostream &output, Rational &r ) {
	//overloaded << will display rational in fractional format
	
	if(r.denominator==1) { //is a whole number
		output << r.numerator << endl;
	} else { //is a fraction
		output << r.numerator << "/" << r.denominator << endl; 
	}

return output;
}