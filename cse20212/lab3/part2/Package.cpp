//Implementation for package (base) class
// Kat Herring and Kate Barlock

#include "Package.h"
#include <string>
#include <iomanip>

Package::Package(string newName, int zipcode, double weight, double costPerOunce){ //constructor

	//initialize all private data members
	Name = newName;
	Zipcode = zipcode;
	setWeight(weight);
	setCost(costPerOunce);
}

void Package::print(){

	//print all package info to screen
	cout << "***Package Stats***" << endl;
	cout << "Name: " << Name << endl << "Zipcode: " << Zipcode << endl;
	cout << "Weight: " << Weight << endl << "Cost per Ounce: $" <<  setprecision(2) << fixed << CostPerOunce << endl;
	cout << "*******************" << endl << endl;
}

void Package::setCost(double costPerOunce){ //set cost of package (w/ error checking)

	while(costPerOunce <= 0){ //error checking. cost per ounce must be positive
		cout << "Error! Cost/Ounce must be a positive quantity! Please input a valid Cost/Ounce: ";
		cin >> costPerOunce;
	}
	CostPerOunce = costPerOunce; //set cost per ounce
}

void Package::setWeight(double weight){ //set weight of package (w/ error checking)

	while(weight <= 0){ //error checking. cost per ounce must be positive
		cout << "Error! Weight must be a positive quantity! Please input a valid weight: ";
		cin >> weight;
	}
	Weight = weight; //set cost per ounce
}

double Package::getWeight(){

	return Weight;
}

double Package::getCostPerOunce(){

	return CostPerOunce;
}

double Package::CalculateCost(){

	return (Weight * CostPerOunce);
}

