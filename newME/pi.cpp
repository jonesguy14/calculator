#include "pi.h"

Pi::Pi() {
    MathExInteger* co	=	new MathExInteger(1);
    this->coefficient.push_back(co);
}


std::string Pi::getName() {
    return "Pi";
}

std::string Pi::toString() {
    return this->getCoefficient()->toString() + "pi";
}

double Pi::toDecimal() {
    return 3.1415926535 * this->getCoefficient()->toDecimal();
}

Expression* Pi::getCoefficient() {
    return this->coefficient.back();
}

void Pi::add(Expression* a) {
    throw Exceptions("Pi cannot add that data type.");
}

void Pi::subtract(Expression* s) {
    throw Exceptions("Pi cannot subtract that data type.");
}

void Pi::multiply(Expression* m) {
    throw Exceptions("Pi cannot multiply that data type.");
}

void Pi::divide(Expression* d) {
    throw Exceptions("Pi cannot divide that data type.");
}

void Pi::add(Pi* a) {
    try {
        this->getCoefficient()->add(a->getCoefficient());
    }
    catch (Exceptions e) {
        Expression* exp = new Expression(this->getCoefficient());
        exp->add(a->getCoefficient());
        this->coefficient.push_back(exp);
    }
}

void Pi::subtract(Pi* s) {
    try {
        this->getCoefficient()->subtract(s->getCoefficient());
    }
    catch (Exceptions e) {
        Expression* exp = new Expression(this->getCoefficient());
        exp->subtract(s->getCoefficient());
        this->coefficient.push_back(exp);
    }
}

void Pi::negative() {
    MathExInteger* neg = new MathExInteger(-1);
    this->getCoefficient()->multiply(neg);
}
