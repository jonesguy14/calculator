#include "Fractions.h"
#include "MathExInteger.h"
#include "Expressions.h"
#include <math.h>

using namespace std;

Fractions::Fractions() {
    MathExInteger numer(1);
    MathExInteger denom(1);
    this->numerator = numer;
    this->numerator = denom;
}

Fractions::Fractions(Expression* numerator, Expression* denominator){
    if (denominator->toDecimal() == 0){
        throw Exceptions("Cannot divide by zero");
    }
    Expression new_num;
    new_num = *numerator;
    new_num.simplify();
    Expression new_den;
    new_den = *denominator;
    new_den.simplify();
    this->numerator = new_num;
    this->denominator = new_den;
    simplify();
}

Expression* getNumerator() {
    return this->numerator.back();
}

Expression* getDenominator() {
    return this->denominator.back();
}

int Fractions::GCDivisor(){
    if (numerator.getName() == "Integer" && denominator.getName() == "Integer") {
        int gcd = 2;
        while (numerator.getInt() % gcd != 0 && denominator.getInt() % gcd != 0){
            gcd++;
        }
        return gcd;
    }
    else {throw Exceptions("Trying to get GCD of non-integer");}
}

void Fractions::simplify(){
    if (numerator.getName() == "Integer" && denominator.getName() == "Integer") {
        int gcd = GCDivisor();
        MathExInteger new_num(numerator.getInt() / gcd);
        numerator = new_num;
        MathExInteger new_den(numerator.getInt() / gcd);
        denominator = new_den;
        if (denominator.getInt() == 1) {
            throw Exceptions("Denominator is equal to 1, don't need fraction");
        }
    }
    else if (toDecimal() - floor(toDecimal()) < 0.000001) {
        int me_int = floor(toDecimal());
        MathExInteger new_num(me_int);
        numerator = new_num;
        MathExInteger new_den(1);
        denominator = new_den;
        throw Exceptions("Denominator is equal to 1, don't need fraction");
    }
    else if (ceil(toDecimal()) - toDecimal() < 0.000001) {
        int me_int = ceil(toDecimal());
        MathExInteger new_num(me_int);
        numerator = new_num;
        MathExInteger new_den(1);
        denominator = new_den;
        throw Exceptions("Denominator is equal to 1, don't need fraction");
    }
}

double Fractions::toDecimal(){
    double decimal = numerator.toDecimal() / denominator.toDecimal();
    return decimal;
}

string Fractions::toString(){
    string str = numerator.toString() + "/" + denominator.toString();
    return str;
}

string Fractions::getName() {
    return "Fraction";
}

void Fractions::add(Expression* addend){
    throw Exceptions("Fraction cannot add that type.");
}

void Fractions::add(Fractions* addend){
    addend->simplify();
    try {
        this->getNumerator()->multiply(addend->getDenominator());
        this->getDenominator()->multiply(addend->getDenominator());
        addend->getNumerator()->multiply(this->getDenominator());
        this->getNumerator()->add(addend->getNumerator());
        simplify();
    } catch (Exceptions e) {
        Expression* expp = new Expression(this->getNumerator());
        expp->multiply(addend->getDenominator());
        Expression* expp2 = new Expression(addend->getNumerator());
        expp2->multiply(this->getDenominator());
        Expression* exppd = new Expression(this->getDenominator());
        exppd->multiply(addend->getDenominator());
        expp->add(expp2);
        expp->divide(exppd);
    }
}

void Fractions::subtract(Fractions* subtrahend){
    try {
        subtrahend->simplify();
        this->getNumerator()->multiply(subtrahend->getDenominator());
        this->getDenominator()->multiply(subtrahend->getDenominator());
        subtrahend->getNumerator()->multiply(this->getDenominator());
        this->getNumerator()->subtract(subtrahend->getNumerator());
        simplify();
    } catch (Exceptions e) {
        Expression* expp = new Expression(this->getNumerator());
        expp->multiply(subtrahend->getDenominator());
        Expression* expp2 = new Expression(subtrahend->getNumerator());
        expp2->multiply(this->getDenominator());
        Expression* exppd = new Expression(this->getDenominator());
        exppd->multiply(subtrahend->getDenominator());
        expp->subtract(expp2);
        expp->divide(exppd);
    }
}

Expression Fractions::multiply(Fractions* multipicand){
    multiplicand->simplify();
    try {
        this->getNumerator()->multiply(multipicand->getNumerator());
        this->getDenominator()->multiply(multiplicand->getDenominator());
        simplify();
    } catch (Exceptions e) {
        Expression* exppn = new Expression(this->getNumerator());
        exppn->multiply(multipicand->getNumerator());
        Expression* exppd = new Expression(this->getDenominator());
        exppd->multiply(multipicand->getDenominator());
        exppn->divide(exppd);
    }
}

Expression Fractions::divide(Fractions* dividend){
    dividend->simplify();
    try {
        this->getNumerator()->multiply(dividend->getDenominator());
        this->getDenominator()->multiply(dividend->getNumerator());
        simplify();
    } catch (Exceptions e) {
        Expression* exppn = new Expression(this->getNumerator());
        exppn->multiply(dividend->getDenominator());
        Expression* exppd = new Expression(this->getDenominator());
        exppd->multiply(dividend->getNumerator());
        exppn->divide(exppd);
    }
}
