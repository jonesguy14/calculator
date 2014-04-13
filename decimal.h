#ifndef DECIMAL_H_
#define DECIMAL_H_

using namespace std;
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
	string toString();
	Fraction toFraction();

};


#endif /* DECIMAL_H_ */
