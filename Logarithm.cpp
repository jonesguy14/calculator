#include "Logarithm.h"
using namespace std;

Logarithm::Logarithm(MathematicalExpression base, MathematicalExpression exponent){
	if(exponent.toDecimal < 0){
		throw "Cannot have the logarithm of a negative number";	
	}
	if(exponent.toDecimal == 0){
		throw "Cannot have the logarithm of 0";
	}
	if(exponent.toDecimal == 1){
		throw "Logarithm is equal to 0";	
	}
	this->base		=	base.simplify();
	this->exponent	=	exponent.simplify();
}

void Logarithm::add(Logarithm* addend){
	if(this->base == addend->getBase){
		/*
			If the bases are the same, we can just multiply the arguments of the logarithm.
		*/
		this->exponent	=	this->exponent.multiply(addend->getExponent());
	}else{
		/*
			If the bases are different, we have to make the addend's base the same as our base, then we can just call this method again.
		*/
		Logarithm* a	=	Logarithm(this.base, addend->getExponent());
		Logarithm* b	=	Logarithm(this.base, addend->getBase());
		a->divide(b);
		this->add(a);
		delete a;
		delete b;
	}
}

void Logarithm::add(MathematicalExpresson* addend){
	/*
		There's nothing we can do if our addend isn't a logarithm, so we'll just tell the parser what happened and move on.
	*/
	throw "Cannot add logarithms to that data type.";
}


void Logarithm::subtract(Logarithm* subtrahend){
	if(this->base == subtrahend->getBase){
		/*
			If the bases are the same, we can just divide the arguments of the logarithm.
		*/
		this->exponent	=	this->exponent.divide(subtrahend->getExponent());
	}else{
		/*
			If the bases are different, we have to make the subtrahend's base the same as our base, then we can just call this method again.
		*/
		Logarithm* a	=	Logarithm(this->base, subtrahend->getExponent());
		Logarithm* b	=	Logarithm(this->base, subtrahend->getBase());
		a->divide(b);
		this->subtract(a);
		delete a;
		delete b;
	}
}

void Logarithm::subtract(MathematicalExpresson* subtrahend){
	/*
		There's nothing we can do if our subtrahend isn't a logarithm, so we'll just tell the parser what happened and move on.
	*/
	throw "Cannot subtract a logarithm from that data type.";
}

void Logarithm::divide(Logarithm* dividend){
	if(this->base == dividend->base){
		this->base	=	dividend->exponent;	
	}else{
		Logarithm* a	=	Logarithm(this->base, dividend->getExponent());
		Logarithm* b	=	Logarithm(this->base, dividend->getBase());
		a->divide(b);
		this->divide(a);
		delete a;
		delete b;
	}
}

void Logarithm::divide(MathematicalExpression* dividend){
	/*
		There's nothing we can do if our dividend isn't a logarithm, so we'll just tell the parser what happened and move on.
	*/
	throw "Cannot divide a logarithm by that data type";
}

void Logarithm::multiply(MathematicalExpression* multiplicand){
	/*
		There are no logarithm rules for multiplication, so we'll just tell the parser what happened and move on.
	*/
	throw "Cannot multiply logarithms";
}

void Logarithm::simplify(){
	this->base.simplify();
	this->exponent.simplify();
}

void Logarithm::toString(){
	return "log_" + this->base.toString() + ":" + this->exponent.toString();
}

MathematicalExpression Logarithm::getExponent(){
	return this->exponent;
}
MathematicalExpression Logarithm::getBase(){
	return this->base;
}
