//Package.h
//Author: Kat Herring & Kate Barlock
// class definition for Package used by shipping companies

#include <string>
#include <iostream>
using namespace std;

#ifndef PACKAGE_H 
#define PACKAGE_H

class Package {

public:
	Package(string newName = "empty", int zipcode = 46556, double weight = 20.0, double costPerOunce = 1.25);
	virtual double CalculateCost();
	void print();
	void setCost(double costPerOunce);
	void setWeight(double weight);
	double getWeight();
	double getCostPerOunce();

private:
	string Name;
	int Zipcode;
	double Weight; //in ounces
	double CostPerOunce; // in dollars
};

#endif
