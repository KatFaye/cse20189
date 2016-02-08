//Class definition of TwoDayPackage (derived from Package class)
// Kat Herring and Kate Barlock

#include "Package.h"

#ifndef TWO_D_PACKAGE_H 
#define TWO_D_PACKAGE_H 


class TwoDayPackage : public Package {
	
public:
	TwoDayPackage(string newName = "empty", int zipcode = 46556, double weight = 20.0, double costPerOunce = 1.25, double flatFee = 5.00);
	virtual double CalculateCost();

private:
	double FlatFee; //initialize in constructor

};

#endif
