//pi.cpp
//Author: Kat Herring
//calculates the value of pi from the infinite series: pi = sum(4/(2n-1))(-1)^n-1

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(void) {
	//initializes needed variables
	double pi = 0;
	int n = 0, i;

	while(n<2) { //continues until valid input given
		cout << "Please input the number of terms (n) to calculate in the series: " << endl;
		cin >> n;
		if(n<2) { //checks if valid input
			cout << "Error! Provided value must be >= 2!" << endl;
		}
	}
	for(i=1;i<=n;i++) { //prints estimate of pi for each term added
		pi += 4/double(2*i-1) * pow(-1, i-1) ;
		cout << "Estimate after " << i << " term(s): " << setprecision(4) << pi << endl;
	}
}
