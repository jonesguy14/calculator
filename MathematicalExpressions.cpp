#include "MathematicalExpressions.h"

using namespace std;

MathematicalExpression::MathematicalExpression() {
    //this will never be called theoretically
}

MathematicalExpression::MathematicalExpression(MathematicalExpression* part1, MathematicalExpression* part2, char op) {
	this->part1	=	part1->simplify();
	this->part2	=	part2->simplify();

	if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^'){
		this->value	=	this->part1->toString() + " " + op + " " + this->part2->toString();
	}else{
		throw "Operator not recognized";
	}
}

MathematicalExpression::MathematicalExpression(int me_int) {
    //only used for MathExInteger
}

void MathematicalExpression::simplify() {
    //simplify
}

MathematicalExpression MathematicalExpression::add(MathematicalExpression* addend){
	addend->simplify();
	string b	=	addend->toString();
	this->value	=	this->value + " " + "+" + " " + b;
}

MathematicalExpression MathematicalExpression::subtract(MathematicalExpression* subtrahend){
	subtrahend->simplify();
	string b	=	subtrahend->toString();
	this->value	=	this->value + " " + "-" + " " + b;
}

MathematicalExpression MathematicalExpression::multiply(MathematicalExpression* multiplicand){
	multiplicand->simplify();
	string b	=	multiplicand->toString();
	this->value	=	this->value + " " + "*" + " " + b;
}

MathematicalExpression MathematicalExpression::divide(MathematicalExpression* dividend){
	dividend->simplify();
	string b	=	dividend->toString();
	this->value	=	this->value + " " + "/" + " " + b;
}

string MathematicalExpression::toString(){
	return this->value;
}
