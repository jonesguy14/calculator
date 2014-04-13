#include "Fractions.h"
#include "MathExInteger.h"
#include "MathematicalExpressions.h"
#include <math.h>

using namespace std;

Fractions::Fractions() {
    MathExInteger numer(1);
    MathExInteger denom(1);
    this->numerator = numer;
    this->numerator = denom;
}

Fractions::Fractions(MathematicalExpression* numerator, MathematicalExpression* denominator){
    if (denominator->toDecimal() == 0){
        throw Exceptions("Cannot divide by zero");
    }
    MathematicalExpression new_num;
    new_num = *numerator;
    new_num.simplify();
    MathematicalExpression new_den;
    new_den = *denominator;
    new_den.simplify();
    this->numerator = new_num;
    this->denominator = new_den;
    simplify();
}

int Fractions::GCDivisor(){
    if (numerator.getName() == "Integer" && denominator.getName() == "Integer") {
        int gcd = 2;
        while (numerator.getInt() % gcd != 0 && denominator.getInt() % gcd != 0){
            gcd++;
        }
        return gcd;
    }
    else {throw "Trying to get GCD of non-integer";}
}

void Fractions::simplify(){
    if (numerator.getName() == "Integer" && denominator.getName() == "Integer") {
        int gcd = GCDivisor();
        MathExInteger new_num(numerator.getInt() / gcd);
        numerator = new_num;
        MathExInteger new_den(numerator.getInt() / gcd);
        denominator = new_den;
        if (denominator.getInt() == 1) {
            throw "Denominator is equal to 1, don't need fraction";
        }
    }
    else if (toDecimal() - floor(toDecimal()) < 0.000001) {
        int me_int = floor(toDecimal());
        MathExInteger new_num(me_int);
        numerator = new_num;
        MathExInteger new_den(1);
        denominator = new_den;
        throw "Denominator is equal to 1, don't need fraction";
    }
    else if (ceil(toDecimal()) - toDecimal() < 0.000001) {
        int me_int = ceil(toDecimal());
        MathExInteger new_num(me_int);
        numerator = new_num;
        MathExInteger new_den(1);
        denominator = new_den;
        throw "Denominator is equal to 1, don't need fraction";
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

MathematicalExpression Fractions::add(MathematicalExpression* addend){
    //addend.simplify();
    //Fractions result;
    //result.numerator =
}

MathematicalExpression Fractions::add(Fractions* addend){
    addend->simplify();
    Fractions result;
    result.numerator = numerator.multiply(&addend->denominator);
    result.numerator = (result.numerator).add(denominator.multiply(&addend->numerator));
    result.denominator = denominator.multiply(&addend->denominator);
    result.simplify();
    return result;
}

MathematicalExpression Fractions::subtract(MathematicalExpression* subtrahend){
    //addend.simplify();
    //Fractions result;
    //result.numerator =
}

MathematicalExpression Fractions::subtract(Fractions* subtrahend){
    subtrahend->simplify();
    Fractions result;
    result.numerator = (numerator * subtrahend.denominator) - (subtrahend.numerator + denominator);
    result.denominator = denominator * subtrahend.denominator;
    result.simplify();
    return result;
}

MathematicalExpression Fractions::multiply(MathematicalExpression* multipicand){
    //addend.simplify();
    //Fractions result;
    //result.numerator =
}

MathematicalExpression Fractions::multiply(Fractions* multipicand){
    multipicand->simplify();
    Fractions result;
    result.numerator = numerator * multipicand.numerator;
    result.denominator = denominator * multipicand.denominator;
    result.simplify();
    return result;
}

MathematicalExpression Fractions::divide(MathematicalExpression* dividend){
    //addend.simplify();
    //Fractions result;
    //result.numerator =
}

MathematicalExpression Fractions::divide(Fractions* dividend){
    dividend->simplify();
    Fractions result;
    result.numerator = numerator * dividend.denominator;
    result.denominator = denominator * dividend.numerator;
    result.simplify();
    return result;
}
