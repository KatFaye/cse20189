//OvernightPackage class definition
// Kat Herring and Kate Barlock

#include "Package.h"

#ifndef O_PACKAGE_H 
#define O_PACKAGE_H

class OvernightPackage : public Package {

public:
	OvernightPackage(string newName = "empty", int zipcode = 46556, double weight = 20.0, double costPerOunce = 1.25, double extraCostPerOunce = .50);
	virtual double CalculateCost();

private:
	double ExtraCostPerOunce;

};

#endif
