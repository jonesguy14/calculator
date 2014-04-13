#include "exp-integer.h"
#include "expression.h"
#include <cmath>

using namespace std;

MathExInteger::MathExInteger() {
    me_int = 0;
}

MathExInteger::MathExInteger(int me_int) { //: me_int(me_int) {
	this->me_int = me_int;
}

Expression MathExInteger::add(Expression* addend){
	if (addend->getName() == "Integer") {
        int result = me_int + addend->getInt();
        MathExInteger meint_result(result);
        return meint_result;
	}
    else {throw "Adding integer for non integer, will provide implementation for fractions once they exist";}
}

Expression MathExInteger::subtract(Expression* subtrahend){
	if (subtrahend->getName() == "Integer") {
        int result = me_int - subtrahend->getInt();
        MathExInteger meint_result(result);
        return meint_result;
	}
	else {throw "Subbing integer for non integer, will provide implementation for fractions once they exist";}
}

Expression MathExInteger::divide(Expression* dividend){
    if (dividend->getName() == "Integer") {
        int result = me_int / dividend->getInt();
        MathExInteger meint_result(result);
        return meint_result;
    }
    else {throw "Dividing integer for non integer, will provide implementation for fractions once they exist";}
}

Expression MathExInteger::multiply(Expression* multiplicand) {
    if (multiplicand->getName() == "Integer") {
        int result = me_int * multiplicand->getInt();
        MathExInteger meint_result(result);
        return meint_result;
    }
    else {throw "Multiplying integer by non int";}
}

void MathExInteger::simplify() {
    //DO NOTHING
}

int MathExInteger::getInt() {
    return me_int;
}

string MathExInteger::toString(){
	return "" + getInt();
}

string MathExInteger::getName() {
    return "Integer";
}

double MathExInteger::toDecimal() {
    return getInt();
}
