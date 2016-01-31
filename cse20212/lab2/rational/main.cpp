// main.cpp
// Author: Kat Herring
//  driver program for Rational class for fraction arithmetic

#include "Rational.h"
#include <iostream>
#include <vector>

using namespace std;

Rational finalVelocity(Rational, Rational, Rational);
Rational force(Rational m, Rational a);
Rational distanceTravelled(Rational v0, Rational a, Rational t);

int main(void) {
	int choice = 0; //rational to access

	vector<Rational> userRational(5);
	Rational result; //used for overloaded calculations
	Rational test(88, 33);
	cout << "Display of test of non-default constructor: " << test << endl;
    while(choice!=4) {

        cout << "\nInteractive mode for Rational Class" << endl;
        cout << "==============" << endl; 
        cout << "Select an option from the menu below" << endl;
        cout << "Compute final velocity on an object - 1" << endl;
        cout << "Calculate force on an object- 2" << endl;
        cout << "Find the distance travelled by an object - 3" << endl; 
        cout << "Quit - 4" << endl;

        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter rational numbers separated by spaces for v0, a, and t (Format of Rational numbers: a/b)" << endl;
                for(int i=0;i<3;i++) {
            		cin >> userRational[i];
            	}
            	userRational[3] = finalVelocity(userRational[0], userRational[1], userRational[2]);
            	cout << "Distance travelled by object is: " << userRational[3];
                break;
            case 2: 
            	cout << "Enter rational numbers separated by spaces for m and a (Format of Rational numbers: a/b)"  << endl;
            	cin >> userRational[0] >> userRational[1];

            	userRational[2] = force(userRational[0], userRational[1]);
            	cout << "Force on object is: " << userRational[2];
                break;
            case 3:
                cout << "Enter rational numbers separated by spaces for v0, a, and t (Format of Rational numbers: a/b)" << endl;
                for(int i=0;i<3;i++) {
            		cin >> userRational[i];
            	}
            	userRational[3] = distanceTravelled(userRational[0], userRational[1], userRational[2]);
            	cout << "Distance travelled by object is: " << userRational[3];
                break;
        }
    }

	return 0;
}
Rational finalVelocity(Rational v0, Rational a, Rational t) {
	//computs final velocity

	Rational velocity;

	velocity = v0 + (a*t);

	return velocity;
}
Rational force(Rational m, Rational a) {
	// computes force on an object
	//F = ma
	Rational force;

	force = m * a;

	return force;
}
Rational distanceTravelled(Rational v0, Rational a, Rational t) {
	//computes distance travelled
	// d = v0*t + .5*a*t^2
	Rational half(1, 2);
	Rational distance;

	distance = (v0*t) + ((half*a)*(t^2));

	return distance;

}