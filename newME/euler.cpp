#include "euler.h"

using namespace std;

Eulers::Eulers() {
    this->coefficient = new MathExInteger(1);
}

Eulers::~Eulers() {
    delete this;
}

string Eulers::getName() {
    return "Eulers";
}

string Eulers::toString() {
    //stringstream s;
    //s << this->coefficient << "e";
    return "e";//s.str();
}

double Eulers::toDecimal() {
    return 2.7182818284;
}

void Eulers::add(Expression* a) {
    if (a->getName() == "Eulers") {
        coefficient = new MathExInteger(a->coefficient->getInt() + coefficient->getInt());
        return this;
    }
}

void Eulers::subtract(Expression* s) {
    if (a->getName() == "Eulers") {
        coefficient = new MathExInteger(coefficient->getInt() - s->coefficient->getInt());
        return this;
    }
}

void Eulers::multiply(Expression* m) {
    if (a->getName() == "Eulers") {
        coefficient = new MathExInteger(m->coefficient->getInt() * coefficient->getInt());
        return this;
    }
}
