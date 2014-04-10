/*
 * decimal.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: asmartin
 */

#include <iostream>
#include "Decimal.h"

Decimal::Decimal(double decimal) {
	this->value = decimal;
}

MathematicalExpression Decimal::add(MathematicalExpression addend) {
	double decimal = value + addend;
	Decimal result(decimal);
	return result;
}

MathematicalExpression  Decimal::subtract(MathematicalExpression subtrahend) {
	double decimal = value - subtrahend;
	Decimal result(decimal);
	return result;
}

MathematicalExpression  Decimal::divide(MathematicalExpression dividend) {
	double decimal = value / dividend;
	Decimal result(decimal);
	return result;
}

MathematicalExpression  Decimal::multiply(MathematicalExpression multiplcand) {
	double decimal = value * multiplcand;
	Decimal result(decimal);
	return result;
}

MathematicalExpression  Decimal::simplify(double decimal) {
	//But really though...how can you simplify a decimal?
}

string  Decimal::toString(double decimal) {
	toString = "" + toDecimal(decimal);
	return toString;
}

double  Decimal::toDecimal(double decimal) {
	return decimal;
}

Fraction  Decimal::toFraction(double decimal) {
	int numerator = decimal;
	String size = toString(decimal);
	String denominator = "" + 1;

	//I have no clue how to do this.
	for(int i =0; i<(size.size()-1); i++) {
		denominator += ("" + 0);
	}

	Fraction fract(int numerator, int denominator);
}
