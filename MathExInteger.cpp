#include "MathExInteger.h"
#include <cmath>
using namespace std;

MathExInteger::MathExInteger(int me_int) : MathematicalExpression(me_int) {
	this->me_int = me_int;
}

MathematicalExpression MathExInteger::add(MathExInteger* addend){
	int result = me_int + addend->getInt();
	MathExInteger meint_result(result);
	return meint_result;
}

MathematicalExpression MathExInteger::add(MathematicalExpression* addend){
	/*
		There's nothing we can do if our addend isn't a logarithm, so we'll just tell the parser what happened and move on.
	*/
	throw "Adding integer for non integer, will provide implementation for fractions once they exist";
}


MathematicalExpression MathExInteger::subtract(MathExInteger* subtrahend){
	int result = me_int - subtrahend->getInt();
	MathExInteger meint_result(result);
	return meint_result;
}

MathematicalExpression MathExInteger::subtract(MathematicalExpression* subtrahend){
	/*
		There's nothing we can do if our subtrahend isn't a logarithm, so we'll just tell the parser what happened and move on.
	*/
	throw "Subtracting integer for non integer, will provide implementation for fractions once they exist";
}

MathematicalExpression MathExInteger::divide(MathExInteger* dividend){
    int result = me_int / dividend->getInt();
	MathExInteger meint_result(result);
	return meint_result;
}

MathematicalExpression MathExInteger::divide(MathematicalExpression* dividend){
	/*
		There's nothing we can do if our dividend isn't a logarithm, so we'll just tell the parser what happened and move on.
	*/
	throw "Dividing integer for non integer, will provide implementation for fractions once they exist";
}

MathematicalExpression MathExInteger::multiply(MathematicalExpression* multiplicand){
	/*
		There are no logarithm rules for multiplication, so we'll just tell the parser what happened and move on.
	*/
	throw "Multiplying integer for non integer, will provide implementation for fractions once they exis";
}

MathematicalExpression MathExInteger::multiply(MathExInteger* multiplicand) {
    int result = me_int * multiplicand->getInt();
	MathExInteger meint_result(result);
	return meint_result;
}

MathematicalExpression MathExInteger::simplify() {
    MathematicalExpression result = *this;
    return result;
}

int MathExInteger::getInt() {
    return me_int;
}

string MathExInteger::toString(){
	return "" + getInt();
}
