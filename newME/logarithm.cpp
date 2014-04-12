#include "logarithm.h"
#include <cmath>
#include <vector>

Logarithm::Logarithm(Expression, Expression, Expression){
	this->coefficient.push_back(coefficient);
	this->base.push_back(base);
	this->argument.push_back(argument);
}
	

Logarithm::Logarithm(Expression coefficient, Expression base, Exponent argument){
	if(base.toDecimal() == argument.getBase().toDecimal()){
		throw "Simple logarithm";
	}else{
			try{
				coefficient.multiply(argument.getExponent());
				this->coefficient.push_back(coefficient);
			}catch(ExpressionException e){
				Expression exp(coefficient);
				exp.multiply(argument.getExponent());
				this->coefficient.push_back(exp);
			}
			this->base.push_back(base);
			this->argument.push_back(argument.getBase());
	}
}
	
	
Logarithm::Logarithm(Expression coefficient, MathExInteger base, MathExInteger argument){
	if(log10(argument.toDecimal())/log10(base.toDecimal()) == floor(log10(argument.toDecimal())/log10(base.toDecimal()))){
		throw "Evaluatable logarithm";
	}else{
		this->coefficient.push_back(coefficient);
		this->base.push_back(base);
		this->argument.push_back(argument);
	}
}

/*
	These 5 methods will throw errors because of various logarithm rules
*/
Logarithm::add(Expression* addend){
	throw "Cannot add an expression to a logarithm";
}
Logarithm::subtract(Expression* addend){
	throw "Cannot subtract an expression from a logarithm";
}
Logarithm::multiply(Expression* addend){
	throw "Cannot multiply an expression with a logarithm";
}
Logarithm::multiply(Logarithm* addend){
	throw "Cannot multiply logarithms";
}
Logarithm::divide(Expression* addend){
	throw "Cannot divide a logarithm by an expression";
}

void Logarithm::add(Logarithm* addend){
	bool samebase	=	addend->getBase().toDecimal() == this->getBase().toDecimal();
	bool samearg	=	addend->getArgument().toDecimal() == this->getArgument().toDecimal();
	if(samebase && samearg){
		try{
			this->coefficient.add(addend->getCoefficient());
		}catch(ExpressionException e){
			Expression exp((this->getCoefficient())*);
			exp->add(addend->getCoefficient());
			this->coefficient.push_back(exp);
		}
	}
	if(samebase && !samearg){
		try{
			this->getArgument().multiply(addend->getArgument());
		}catch(ExpressionException e){
			Expression exp(this->getArgument());
			exp->multiply(addend->getArgument());
			this->argument.push_back(exp);
		}
		try{
			this->coefficient.add(addend->getCoefficient());
		}catch(ExpressionException e){
			Expression exp2((this->getCoefficient())*);
			exp2->add(addend->getCoefficient());
			this->coefficient.push_back(exp2);
		}
	}
	if(!samebase && !samearg){
		throw "Cannot add logarithms with different bases";
	}
}

void Logarithm::subtract(Logarithm* subtrahend){
	bool samebase	=	subtrahend->getBase().toDecimal() == this->getBase().toDecimal();
	bool samearg	=	subtrahend->getArgument().toDecimal() == this->getArgument().toDecimal();
	if(samebase && samearg){
		try{
			this->coefficient.subtract(subtrahend->getCoefficient());
		}catch(ExpressionException e){
			Expression exp((this->getCoefficient())*);
			exp->subtract(subtrahend->getCoefficient());
			this->coefficient.push_back(exp);
		}
	}
	if(samebase && !samearg){
		try{
			this->getArgument().divide(subtrahend->getArgument());
		}catch(ExpressionException e){
			Expression exp(this->getArgument());
			exp->divide(subtrahend->getArgument());
			this->argument.push_back(exp);
		}
		try{
			this->coefficient.subtract(subtrahend->getCoefficient());
		}catch(ExpressionException e){
			Expression exp2((this->getCoefficient())*);
			exp2->subtract(subtrahend->getCoefficient());
			this->coefficient.push_back(exp2);
		}
	}
	if(!samebase && !samearg){
		throw "Cannot subtract logarithms with different bases";
	}
}

void Logarithm::divide(Logarithm* dividend){
	this->base.push_back(dividend->getArgument());
}

void Logarithm::simplify(){
	// Do nothing
}

std::string Logarithm::toString(){
	std::string result	=	"";
	result	+=	this->getCoefficient().toString();
	result	+=	"log_";
	result	+=	this->getBase().toString();
	result	+=	":(";
	result	+=	this->getArgument().toString();
	result	+=	")";
}

double Logarithm::toDecimal(){
	double log	=	log10(this->getArgument().toDecimal())/log10(this->getBase().toDecimal());
	log *=	this->getCoefficient().toDecimal();
	return log;
}

Expression Logarithm::getCoefficient(){
	return this->coefficient.back();
}
Expression Logarithm::getBase(){
	return this->base.back();
}
Expression Logarithm::getArgument(){
	return this->argument.back();
}
