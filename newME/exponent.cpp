#include "Exponent.h"

using namespace std;

/*
Exponent::Exponent(MathExInteger base, MathExInteger power){
if(power.getInt() < 0){
	throw //Exponent Class: power < 0, convert to fraction
}

if(power.getInt() == 0){
	throw //Exponent Class: power = 0, convert to 1
}

if(power.getInt() == 1){
	throw //Exponent Class: power == 1, convert to integer
}

if(base.getInt() == 0){
	throw //Exponent Class: base == 0, convert to 0
}

if(base.getInt() == 1){
	throw //Exponent Class: base == 1, convert to 1
}

if((base.getInt() == 0) && (power.getInt() == 0){
	throw //Entire expression is undefined
}

this->intBase = base;
this->intPower = power;

this->_intBase = true;
this->_intPow = true;
this->_expBase = false;
this->_expPow = false;

};

Exponent::Exponent(MathExInteger base, Expression power){

if(base.getInt() == 0){
	throw //Exponent Class: base == 0, convert to 0
}

if(base.getInt() == 1){
	throw //Exponent Class: base == 1, convert to 1
}

this->intBase = base;
this->expPower = simplify(power);

this->_intBase = true;
this->_intPow = false;
this->_expBase = false;
this->_expPow = true;

};

Exponent::Exponent(MathematicalExpression base, MathExInteger power){
if(power.getInt() < 0){
	throw //Exponent Class: power < 0, convert to fraction
}

if(power.getInt() == 0){
	throw //Exponent Class: power = 0, convert to 1
}

if(power.getInt() == 1){
	throw //Exponent Class: power == 1, convert to integer
}

if(base.getInt() == 0){
	throw //Exponent Class: base == 0, convert to 0
}

this->expBase = simplify(base);
this->intPower = power;

this->_intBase = false;
this->_intPow = true;
this->_expBase = true;
this->_expPow = false;

};

Exponent::Exponent(MathematicalExpression base, MathematicalExpression power){

this->expBase = simplify(base);
this->expPower = simplify(power);

this->_intBase = false;
this->_intPow = false;
this->_expBase = true;
this->_expPow = true;

};

bool isIntBase(){
	return this->isIntBase;
}

bool isIntPow(){
	return this->isIntPow;
}

bool isExpBase(){
	return this->isExpBase;
}

bool isExpPow(){
	return this->isExpPow;
}

*/

Exponent::Exponent(Expression coefficient, Expression base, Expression power){
if(power.toDecimal() < 0){
	throw Exceptions("Exponent Class: power < 0, convert to fraction");
}

if(power.toDecimal() == 0){
	throw Exceptions("Exponent Class: power = 0, convert to 1");
}

if(power.toDecimal() == 1){
	throw Exceptions("Exponent Class: power == 1, convert to integer");
}

if(base.toDecimal() == 0){
	throw Exceptions("Exponent Class: base == 0, convert to 0");
}

if(base.toDecimal() == 1){
	throw Exceptions("Exponent Class: base == 1, convert to 1");
}

if((base.toDecimal() == 0) && (power.toDecimal() == 0){
	throw Exceptions("Entire expression is undefined");
}

this->coefficient.push_back(coefficient);
this->base.push_back(base);
this->power.push_back(power);

}

Exponent::Exponent(Expression coefficient, Expression base, Logarithm power){
if(power.toDecimal() < 0){
	throw Exceptions("Exponent Class: power < 0, convert to fraction");
}

if(power.toDecimal() == 0){
	throw Exceptions("Exponent Class: power = 0, convert to 1");
}

if(power.toDecimal() == 1){
	throw Exceptions("Exponent Class: power == 1, convert to integer");
}

if(base.toDecimal() == 0){
	throw Exceptions("Exponent Class: base == 0, convert to 0");
}

if(base.toDecimal() == 1){
	throw Exceptions("Exponent Class: base == 1, convert to 1");
}

if((base.toDecimal() == 0) && (power.toDecimal() == 0){
	throw Exceptions("Entire expression is undefined");
}

if (base.toDecimal() == power.getBase().toDecimal()){
	throw Exceptions("Exponent Class: evaluable exponent");




}


Exponent::Exponent(Expression coefficient, MathExInteger base, MathExInteger power){
if(power.toDecimal() < 0){
	throw Exceptions("Exponent Class: power < 0, convert to fraction");
}

if(power.toDecimal() == 0){
	throw Exceptions("Exponent Class: power = 0, convert to 1");
}

if(power.toDecimal() == 1){
	throw Exceptions("Exponent Class: power == 1, convert to integer");
}

if(base.toDecimal() == 0){
	throw Exceptions("Exponent Class: base == 0, convert to 0");
}

if(base.toDecimal() == 1){
	throw Exceptions("Exponent Class: base == 1, convert to 1");
}

if((base.toDecimal() == 0) && (power.toDecimal() == 0){
	throw Exceptions("Entire expression is undefined");
}


}

Exponent::~Exponent(){
	delete[] this->expCoefficient;
	delete[] this->expBase;
	delete[] this->expPower;
	delete[] this->intBase;
	delete[] this->intPower;
	delete this;

}

Expresssion Exponent::getCoefficient(){
	return this->coefficient.back();
}

Expression Exponent::getBase(){
	return this->base.back();
}

Expression Exponent::getPower(){
	return this->power.back();
}

void Exponent::add(Exponent* addend){

bool sameBase = addend->getBase().toDecimal() == this->getBase().toDecimal();
bool samePow  = addend->getPower().toDecimal() == this->getPower().toDecimal();
	if(sameBase && samePow){
		try{
			this->coefficient.add(addend->getCoefficient());
		}catch(ExpressionException e){
			Expression exp((this->getCoefficient())*);
			exp->add(addend->getCoefficient());
			this->coefficient.push_back(exp);
		}
	}
}

void Exponent::add(MathematicalExpression* addend){

	throw //Exponent::addMathExp : add exponent to math expression

}


void Exponent::multiply(Exponent* multiplicand){

if(this->isIntBase() && multiplicand->isIntBase()){//If both bases are MathExInteger's

	if(this->intBase == multiplicand->intBase){//If int bases match, exponents can be added

		if(this->isExpPow() && multiplicand->isExpPow()){//If both powers are expressions

			throw //Exponent::multiplyExponent : Add two powers; (this power is expression), (multiplicand power is expression); this->expPower = to the result

		}
		else if(this->isExpPow() && multiplicand->isIntPow()){//If first power is expression, and the other an integer

			throw //Exponent::multiplyExponent : Add two powers; (this power is expression), (multiplicand power is integer);  set this->expPower = to the result 
		}
		else{//There should not be a case of two base integers and two power integers (because if there were, they should have been simplified to an integer)

			throw //Exponent::multiplyExponent : Add two powers; (this power is integer), (multiplicand power is expression);  set this->expPower = to the result 
		}

	}
}

else if((this->isExpBase() && multiplicand->isExpBase()){//Else if both bases are MathExpression's

	if(this->expBase == multiplicand->expBase){//If expression bases match, exponents can be added

		if(this->isExpPow() && multiplicand->isExpPow()){//If both powers are expressions

			throw //Exponent::multiplyExponent : Add two powers; (this power is expression), (multiplicand power is expression); this->expPower = to the result

		}
		else if(this->isExpPow() && multiplicand->isPow()){//If first power is expression, and the other an integer

			throw //Exponent::multiplyExponent : Add two powers; (this power is expression), (multiplicand power is integer);  set this->expPower = to the result
		}
		else if(this->isInt() && multiplicand->isPow()){//If first power is integer, and the other an expression

			throw //Exponent::multiplyExponent : Add two powers; (this power is integer), (multiplicand power is expression);  set this->expPower = to the result
		}
		else{//Both powers are integers
			this->intPower = this->intPower.add(multiplicand->intPower); //add method from MathExInteger Class called

		}

	}

}

else{

	throw //

     }

}

string Exponent::getName(){
	return "Exponent";
}


MathematicalExpression Exponent::simplify(MathematicalExpression* mathExp){
	mathExp->simplify();

}
