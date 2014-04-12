#include "E.h"

using namespace std;

E::E() {
    this->coeffecient = new MathExInteger(1);
}

E::~E() {
    delete this;
}

string E::getName() {
    return "E";
}

string E::toString() {
    stringstream s;
    s << this->coefficient << "E";
    return s.str();
}

double E::toDecimal() {
    return 2.7182818284;
}

Expression* E::add(Expression* a) {
    if a->getName() == "E" {
        coefficient = new MathExInteger(a->coefficient->getInt() + coefficient->getInt());
        return this;
    }
}

Expression* E::subtract(Expression* s) {
    if a->getName() == "E" {
        coefficient = new MathExInteger(coefficient->getInt() - s->coefficient->getInt());
        return this;
    }
}

Expression* E::multiply(Expression* m) {
    if a->getName() == "E" {
        coefficient = new MathExInteger(m->coefficient->getInt() * coefficient->getInt());
        return this;
    }
}
