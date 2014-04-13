#ifndef DECIMAL_H_
#define DECIMAL_H_

#include "expression.h"
#include "fraction.h"
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
	Expression add(Expression addend);
	Expression subtract(Expression subtrahend);
	Expression divide(Expression dividend);
	Expression multiply(Expression multiplicand);
	Expression simplify();
	std::string toString();
	Fractions toFraction();

};


#endif /* DECIMAL_H_ */
