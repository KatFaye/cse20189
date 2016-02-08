//OvernightPackage class implementation
// Kat Herring and Kate Barlock

#include "OvernightPackage.h"
#include "Package.h"

OvernightPackage::OvernightPackage(string newName, int zipcode, double weight, double costPerOunce, double extraCostPerOunce): Package (newName, zipcode, weight, costPerOunce){ //constructor

	ExtraCostPerOunce = extraCostPerOunce;

}

double OvernightPackage::CalculateCost(){

	setCost(getCostPerOunce() + ExtraCostPerOunce); //adds extra charge
	double cost = Package::CalculateCost(); 
	return cost;
}
