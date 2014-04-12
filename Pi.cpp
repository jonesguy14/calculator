#include "Pi.h"

using namespace std;

Pi::Pi() {
    this->coeffecient = new MathExInteger(1);
}

Pi::~Pi() {
    delete this;
}

string Pi::getName() {
    return "Pi";
}

string Pi::toString() {
    stringstream s;
    s << this->coefficient << "pi";
    return s.str();
}

double Pi::toDecimal() {
    return 3.1415926535;
}

Expression* Pi::add(Expression* a) {
    if a->getName() == "Pi" {
        coefficient = new MathExInteger(a->coefficient->getInt() + coefficient->getInt());
        return this;
    }
}

Expression* Pi::subtract(Expression* s) {
    if a->getName() == "Pi" {
        coefficient = new MathExInteger(coefficient->getInt() - s->coefficient->getInt());
        return this;
    }
}

Expression* Pi::multiply(Expression* m) {
    if a->getName() == "Pi" {
        coefficient = new MathExInteger(m->coefficient->getInt() * coefficient->getInt());
        return this;
    }
}
