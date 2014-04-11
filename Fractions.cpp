#include "Fractions.h"
#include "MathematicalExpressions.h"

using namespace std;

Fractions::Fractions(MathematicalExpression numerator, MathematicalExpression denominator){
    if (denominator.toDecimal() == 0){
        throw "Cannot divide by zero";
    }
    this->numerator = numerator.simplify();
    this->denominator = denominator.simplify();
    simplify();
}

int Fractions::GCDivisor(){
    int gcd = 2;
    while (numerator.getInt() % gcd != 0 && denominator.getInt() % gcd != 0){
        gcd++;
    }
    return gcd;
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
        MathExInteger new_num(floor(toDecimal());
        numerator = new_num;
        MathExInteger new_den(1);
        denominator = new_den;
        throw "Denominator is equal to 1, don't need fraction";
    }
    else if (ceil(toDecimal()) - toDecimal() < 0.000001) {
        MathExInteger new_num(ceil(toDecimal());
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
    string str = toString(numerator) + "/" + toString(denominator);
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
    addend.simplify();
    Fractions result;
    result.numerator = (numerator * addend.denominator) + (addend.numerator + denominator);
    result.denominator = denominator * addend.denominator;
    result.simplify();
    return result;
}

MathematicalExpression Fractions::subtract(MathematicalExpression* subtrahend){
    //addend.simplify();
    //Fractions result;
    //result.numerator =
}

MathematicalExpression Fractions::subtrahend(Fractions* subtrahend){
    subtrahend.simplify();
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

MathematicalExpression Fractions::multipicand(Fractions* multipicand){
    multipicand.simplify();
    Fractions result;
    result.numerator = numerator * multipicand.numerator;
    result.denominator = denominator * multipicand.denominator;
    result.simplify();
    return result;
}

MathematicalExpression Fractions::multiply(MathematicalExpression* dividend){
    //addend.simplify();
    //Fractions result;
    //result.numerator =
}

MathematicalExpression Fractions::dividend(Fractions* dividend){
    dividend.simplify();
    Fractions result;
    result.numerator = numerator * dividend.denominator;
    result.denominator = denominator * dividend.numerator;
    result.simplify();
    return result;
}
