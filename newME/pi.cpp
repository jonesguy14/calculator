#include "Pi.h"

Pi::Pi() {
	MathExInteger i(1);
    this->coeffecient.push_back(i);
}

Pi::~Pi() {
    delete this;
}

std::string Pi::getName() {
    return "Pi";
}

std::string Pi::toString() {
    return this->getCoefficient().toString() << "pi";
}

double Pi::toDecimal() {
    return 3.1415926535;
}

void Pi::add(Pi* a){
	try{
		this->getCoefficient().add(a->getCoefficient());
	}catch(Exceptions e){
		Expression exp(a->getCoefficient());
		exp.add(this->getCoefficient());
		this->coefficient.push_back(exp);
	}
}

void Pi::add(Expression* a) {
    throw Exceptions("Cannot add a constant to that type");
}
void Pi::subtract(Pi* s) {
	try{
		this->getCoefficient().subtract(s->getCoefficient());
	}catch(Exceptions e){
		Expression exp(this->getCoefficient());
		exp.subtract(s->getCoefficient());
		this->coefficient.push_back(exp);
	}
}
void Pi::subtract(Expression* a) {
    throw Exceptions("Cannot subtract a constant from that type");
}

void Pi::multiply(Expression* m) {
    throw Exceptions("Cannot multiply a constant with that type");
}

void Pi::divide(Expression* d) {
    throw Exceptions("Cannot divide a constant by that type");
}

Expression Pi::getCoefficient(){
	return this->coefficient.back();
}
