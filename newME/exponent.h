#ifndef EXPONENT_H_
#define EXPONENT_H_

#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

#include "expression.h"
#include "exp-integer.h"
#include "logarithm.h"

using namespace std;

class Exponent: public Expression{

private:
	vector<Expression*> base;
	vector<Expression*> power;
	vector<Expression*> coefficient;

public:
	Exponent(Expression, Expression, Expression);
	Exponent(Expression, Expression, Logarithm);
	Exponent(Expression, MathExInteger, MathExInteger);
	~Exponent();
	
	Expression* getCoefficient();
	Expression* getBase();
	Expression* getPower();

	void add(Expression* addend);
	void subtract(Expression* subtrahend);
	void multiply(Expression* multiplicand);
	void divide(Expression* dividend);

	void add(Exponent* addend);	
	void subtract(Exponent* subtrahend);
	void multiply(Exponent* multiplicand);
	void divide(Exponent* dividend);

	void simplify();

	double toDecimal();

	string toString();
	string getName();	

};


#endif /*EXPONENT_H_*/
