// driver program for Packages class and derived classes
// Kat Herring and Kate Barlock

#include <iostream>
#include <iomanip>
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std;

int main(){
	
	//instantiate three objects of different package types
	Package pack1("Kate's Regular Package", 46556, 15, 2.50);
	TwoDayPackage twoDayPack1("Kate's Two Day Package", 46556, 15, 2.50);
	OvernightPackage overnightPack1("Kate's Overnight Package", 46556, 15, 2.50);

	Package * ptr1 = &twoDayPack1, * ptr2 = &overnightPack1; //create base class pointers to derived class objects

	pack1.print();
	ptr1 -> print(); //use base class's print function
	ptr2 -> print(); //use base class's print function

	//Print final costs of all instantiated packages
	cout << "Cost of a regular package: $" << setprecision(2) << fixed << pack1.CalculateCost() << endl;
	cout << "Cost of a two day package: $" << setprecision(2) << fixed << twoDayPack1.CalculateCost() << endl;
	cout << "Cost of an overnight package: $" << setprecision(2) << fixed << overnightPack1.CalculateCost() << endl;

	return 0;
}