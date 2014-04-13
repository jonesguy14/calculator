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
	vector<Expression*> expBase;
	vector<Expression*> expPower;
	vector<Expression*> expCoefficient;

	vector<MathExInteger*> intBase;
	vector<MathExInteger*> intPower;

	//MathExInteger exponentValue;
	//bool _intBase;
	//bool _intPow;
	//bool _expBase;
	//bool _expPow;

public:
	//MathematicalExpression expBase, expPower;
	//MathExInteger intBase, intPower;

	Exponent(Expression, Expression, Expression);
	Exponent(Expression, Expression, Logarithm);
	Exponent(Expression, MathExInteger, MathExInteger);
	~Exponent();
	//Exponent(MathExInteger, Expression);
	//Exponent(Expression, MathExInteger);
	
	//bool isIntBase();
	//bool isIntPow();
	//bool isExpBase();
	//bool isExpPow();

	
	Expression* getCoefficient();
	Expression* getBase();
	Expression* getPower();

	void add(Exponent* addend);	
	void add(Expression* addend);
	
	void subtract(Exponent* subtrahend);
	void subtract(Expression* subtrahend);

	void divide(Exponent* dividend);
	void divide(Expression* dividend);

	void multiply(Exponent* multiplicand);
	void multiply(Expression* multiplicand);

	void simplify();

	double toDecimal();

	string toString();
	string getName();	

};


#endif /*EXPONENT_H_*/
