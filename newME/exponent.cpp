#include "Exponent.h"

using namespace std;

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
		throw Exceptions("Exponent Class: Entire expression is undefined");
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
		throw Exceptions("Exponent Class: Entire expression is undefined");
	}

	if (base.toDecimal() == power.getBase().toDecimal()){
		throw Exceptions("Exponent Class: evaluable exponent with expression base and logarithm power");
	}

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
		throw Exceptions("Exponent Class: Entire expression is undefined");
	}

	if(pow(base.toDecimal(),power.toDecimal())==floor(pow(base.toDecimal(),power.toDecimal())){
		throw Exceptions("Exponent Class: evaluable exponent with MathExInteger base and MathExInteger power");

	}

	//Should not get to this point because the exponent should always be evaluable since base and power are of type MathExInteger
	this->coefficient.push_back(coefficient);
	this->base.push_back(base);
	this->power.push_back(power);


}

Exponent::~Exponent(){
	delete[] this->coefficient;
	delete[] this->base;
	delete[] this->power;
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

void Exponent::add(Expression* addend){

	throw Exceptions("Exponent::add(Expression*) : add math expression to exponent");

}

void Exponent::subtract(Expression* subtrahend){
	if(this->toDecimal() == subtrahend->toDecimal){
		throw Exceptions("Exponent::subtract(Expression*) : subtraction of same values, convert to 0");
	}
	else
	throw Exceptions("Exponent::subtract(Expression*) : subtract math expression from exponent");

}

void Exponent::multiply(Expression* multiplicand){

	throw Exceptions("Exponent::multiply(Expression*) : multiply math expression to exponent");

}

void Exponent::divide(Expression* dividend){

	throw Exceptions("Exponent::divide(Expression*) : divide math expression from exponent");

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
	else{
		throw Exceptions("Exponent::add(Exponent*) : add exponent to exponent");
	}
}

void Exponent::subtract(Exponent* subtrahend){

bool sameCoeff = subtrahend->getCoefficient().toDecimal() == this->getCoefficient().toDecimal();
bool sameBase = subtrahend->getBase().toDecimal() == this->getBase().toDecimal();
bool samePow  = subtrahend->getPower().toDecimal() == this->getPower().toDecimal();

	if(sameCoeff && sameBase && samePow){
		throw Exceptions("Exponent::subtract(Exponent*) : subtraction of same exponents, convert to 0");
	}
	if(sameBase && samePow){
		try{
			this->coefficient.subtract(subtrahend->getCoefficient());
		}catch(ExpressionException e){
			Expression exp((this->getCoefficient())*);
			exp->subtract(subtrahend->getCoefficient());
			this->coefficient.push_back(exp);
		}
	}
	else{
		throw Exceptions("Exponent::subtract(Exponent*) : subtract exponent from exponent");
	}
}


void Exponent::multiply(Exponent* multiplicand){

bool sameCoeff = multiplicand->getCoefficient().toDecimal() == this->getCoefficient().toDecimal();
bool sameBase = multiplicand->getBase().toDecimal() == this->getBase().toDecimal();
bool samePow  = multiplicand->getPower().toDecimal() == this->getPower().toDecimal();

	if(sameBase){
		try{
			this->coefficient.multiply(multiplicand->getCoefficient());
			this->power.add(multiplicand->getPower());
		}catch(ExpressionException e){
			Expression exp1((this->getCoefficient())*);
			Expression exp2((this->getPower())*);
			exp1->multiply(multiplicand->getCoefficient());
			exp2->add(multiplicand->getPower());
			this->coefficient.push_back(exp1);
			this->power.push_back(exp2);
		}
	}
	else{
		throw Exceptions("Exponent::multiply(Exponent*) : multiply exponent to exponent");
	}

}

void Exponent::divide(Exponent* dividend){

bool sameCoeff = dividend->getCoefficient().toDecimal() == this->getCoefficient().toDecimal();
bool sameBase = dividend->getBase().toDecimal() == this->getBase().toDecimal();
bool samePow  = dividend->getPower().toDecimal() == this->getPower().toDecimal();

	if(sameBase){
		try{
			this->coefficient.divide(dividend->getCoefficient());
			this->power.subtract(dividend->getPower());
		}catch(ExpressionException e){
			Expression exp1((this->getCoefficient())*);
			Expression exp2((this->getPower())*);
			exp1->divide(dividend->getCoefficient());
			exp2->subtract(dividend->getPower());
			this->coefficient.push_back(exp1);
			this->power.push_back(exp2);
		}
	}
	else{
		throw Exceptions("Exponent::divide(Exponent*) : divide exponent by exponent");
	}

}

void Exponent::negative(){
	this->getCoefficient().negative();

}

void Exponent::simplify(){
	//do nothing

}

double Exponent::toDecimal(){
	double exponentVal = pow(this->getBase.toDecimal(),this->getPower.toDecimal());
		exponentVal *= this->getCoefficient.toDecimal();
	return exponentVal;

}

string Exponent::toString(){
	ostringstream ss;
	  ss << this->getCoefficient().toString() 
	     << "(" << this->getBase().toString()
	     << "^" << this->getPower().toString()
	     << ")";
	}
	return ss.str();

}

string Exponent::getName(){
	return "Exponent";
}

