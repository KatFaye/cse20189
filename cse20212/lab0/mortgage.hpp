//mortgage.hpp
//class definitions for mortgage calculator
//Author: Kat Herring

#ifndef MORTGAGE_HPP_
#define MORTGAGE_HPP_

class Mortgage {
public:
	Mortgage();
	Mortgage(double, double, double);
	void amortize();
	double getPrincipal();
	void credit(double);
	void interestPaymentCalc();
	double interestPaymentCalc(double);

private:
	double principal;
	double rate;
	double payment;
	double interestPayment; //lowest payment to keep principal from increase

};

#endif //MORTGAGE_HPP_