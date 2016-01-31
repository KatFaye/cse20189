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
    if(newNum!=0) {
	   numerator = newNum;
    } else {
        cout << "Error: Numerator cannot be zero; setting numerator to one." << endl;
    }

	simplifyRational();
}
int Rational::getDenominator() {
    if(denominator==0) {
        cout << "Error: denominator cannot be zero. Setting to 1" << endl;
        denominator = 1;
    }
    return denominator;
}
void Rational::setNumerator(int newNum) {
    if(newNum==0) {
         cout << "Error: numerator cannot be zero. Setting to 1." << endl;
         newNum = 1;
    }
    numerator = newNum;
}
void Rational::setDenominator(int newDenom) {
    if(newDenom==0) {
        cout << "Error: denominator cannot be zero. Setting to 1" << endl;
        newDenom = 1;
    }
    denominator = newDenom;
}
int Rational::getNumerator() {
    if(numerator==0) {
        cout << "Error: numerator cannot be zero. Setting to 1." << endl;
    }
    return numerator;
}
void Rational::setRational() {
    cout << "Input rational in fractional format (i.e a/b)" << endl;

    cin >> (*this);

    simplifyRational();
    cout << "New value of Rational: " << (*this);
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
	GCD = findGCD();
	numerator = numerator/GCD;
	denominator = denominator/GCD;

    if(denominator<0&&numerator>0) { //flips negative sign to top of fraction
        numerator = -numerator;
        denominator = abs(denominator);
    } else if(denominator<0&&numerator<0) { //negative over negative = positive
        numerator = abs(numerator);
        denominator = abs(denominator);
    }

	return 0;
}
ostream &operator<<(ostream &output, Rational &r ) {
	//overloaded << will display rational in fractional format
	r.simplifyRational(); //simplify rational before displaying it

	if(r.denominator==1) { //is a whole number
		output << r.numerator << endl;
	} else { //is a fraction
		output << r.numerator << "/" << r.denominator << endl; 
	}

return output;
}
istream &operator>>(istream &input, Rational &r) {
    //overloaded >> will take a rational number as an input
   input >> r.numerator;
   char c;
   input >> c; //this will "trap" the fraction bar
   input >> r.denominator;
   return input; 
}
Rational Rational::operator*(Rational r) {
    Rational result; //temp object for calculating result
    int ans;

    ans = numerator * r.getNumerator();
    result.setNumerator(ans);
    ans = denominator * r.getDenominator();
     result.setDenominator(ans);

    return result;
}
Rational Rational::operator+(Rational r) {
    Rational result; //temp object for calculating result
    int ans;
    int denom1 = denominator, denom2 = r.getDenominator(), num2;
    //cross-multiply to find common denominator and equivalent fractions
    denominator = denom1 * denom2;
    r.setDenominator(denominator);
    numerator = numerator * denom2;
    num2 = r.getNumerator() * denom1;
    r.setNumerator(num2);

    ans = r.getNumerator() + numerator;
    result.setNumerator(ans);
    result.setDenominator(denominator);

    return result;
}
Rational Rational::operator-(Rational r) {
    Rational result; //temp object for calculating result
    int ans;
    //cross multiply to find common denominator and equivalent fractions
    int denom1 = denominator, denom2 = r.getDenominator(), num2;
    denominator = denom1 * denom2;
    r.setDenominator(denominator);
    numerator = numerator * denom2;
    num2 = r.getNumerator() * denom1;
    r.setNumerator(num2);

    ans = r.getNumerator() - numerator;
    result.setNumerator(ans);
    result.setDenominator(denominator);

    return result;
}
Rational Rational::operator/(Rational r) {
    Rational result; //temp object for calculating result
    int ans;

    ans = numerator / r.getNumerator();
    result.setNumerator(ans);
    ans = denominator / r.getDenominator();
    result.setDenominator(ans);

    return result;
}
Rational Rational::operator^(int power) {
    //overload ^ in order to raise rational to a given power
    Rational result;
    int ans;

    for(int i=0;i<power;i++) { //multiplies number by itself until raised to appropriate power
        ans = numerator * result.getNumerator();
        result.setNumerator(ans);
        ans = denominator * result.getDenominator();
        result.setDenominator(ans);
    }

    return result;
}