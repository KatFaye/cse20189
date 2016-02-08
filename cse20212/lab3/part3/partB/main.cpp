// driver program for Packages class and derived classes
// Kat Herring and Kate Barlock

#include <iostream>
#include <iomanip>
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std;

int main(){
	
	//instantiate 3 Two Day Packages
	TwoDayPackage TPack1("Kat's Two Day Package", 46556, 15, 2.50), TPack2("Scott's Two Day Package", 46556, 20, 1.50), TPack3("Ramzi's Two Day Package", 46556, 18, 3.25);
	//instantiate 3 Overnight Packages
	OvernightPackage OPack1("Kate's Overnight Package", 46556, 15, 2.50), OPack2("Scotts's Overnight Package", 46556, 20, 1.50), OPack3("Ramzi's Overnight Package", 46556, 18, 3.25);

	//make array of package pointers
	Package * PackageArray[6] = {&TPack1, &TPack2, &TPack3, &OPack1, &OPack2, &OPack3}; //create base class pointers to derived class objects

	for(int i = 0; i < 6; i++){

		cout << "The total cost of " << PackageArray[i] -> getName() << " is $" << fixed << setprecision(2) << (PackageArray[i] -> CalculateCost()) << endl;

	}

	return 0;
}