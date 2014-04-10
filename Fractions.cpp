#include "Fractions.h"
#include "MathematicalExpressions.cpp"

Fractions::Fractions(MathematicalExpression numerator, MathematicalExpression denominator){
    if (denominator.toDecimal() == 0){
        throw "Cannot divide by zero";
    }
    this->numerator = numerator.simplify();
    this->denominator = denominator.simplify();
}

void Fractions::GCD(Fractions F1, Fractions F2){
    int GCD = F1.denominator * F2.denominator;
    int F1N = F1.numerator * F2.denominator;
    int F2N = F2.numerator * F1.denominator;
    F1.numerator = F1N;
    F2.numerator = F2N;
    F1.denominator = GCD;
    F2.denominator = GCD;
}

int GCDivisor(){
    while (numerator % temp1 != 0 && denominator % temp1 != 0){
        temp1++;
    }
    return temp1;
}

void Fractions::simplify(){
    numerator = numerator/GCDivisor();
    denominator = denominator/GCDivisor();
}

double Fractions::toDecimal(){
    double decimal = numerator/denominator;
    return decimal;
}

std::string Fractions::toString(){
    string str = numerator + "/" + denominator;
    return str;
}

void add(MathematicalExpression* addend){
    addend.simplify();
    
}
