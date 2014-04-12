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
	MathematicalExpression add(MathematicalExpression addend);
	MathematicalExpression subtract(MathematicalExpression subtrahend);
	MathematicalExpression divide(MathematicalExpression dividend);
	MathematicalExpression multiply(MathematicalExpression multiplicand);
	MathematicalExpression simplify();
	string toString();
	Fraction toFraction();

};


#endif /* DECIMAL_H_ */
