#ifndef DECIMAL_H_
#define DECIMAL_H_

#include "expression.h"
#include "fraction.h"
#include "math.h"
#include <iostream>

class Decimal {

private:
	double value;

public:
	//Constructors
	Decimal(double decimal);

	//Destructors
	~Decimal() {
	};

	//Methods
	void add(Expression addend);
	void subtract(Expression subtrahend);
	void divide(Expression dividend);
	void multiply(Expression multiplicand);
	void simplify();
	string toString();
	double getDecimal();
	Fraction toFraction(double decimal);
	void toFrac();

};


#endif /* DECIMAL_H_ */
