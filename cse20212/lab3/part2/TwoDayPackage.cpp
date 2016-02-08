//Implementation of TwoDayPackage derived class (base class is Package)
// Kat Herring and Kate Barlock

#include "Package.h"
#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(string newName, int zipcode, double weight, double costPerOunce, double flatFee) : Package (newName, zipcode, weight, costPerOunce){

	FlatFee = flatFee;
}

double TwoDayPackage::CalculateCost(){ //calculate shipping cost

	double weight = getWeight();
	double cPO = getCostPerOunce();

	return (weight * cPO + FlatFee); //return cost with flat fee factored in

} 
