#ifndef __calculator__Fractions__
#define __calculator__Fractions__

#include <iostream>
#include <vector>
#include "expression.h"


class Fractions : public Expression{
private:
    std::vector<Expression*> numerator;
    std::vector<Expression*> denominator;

public:
    Fractions(Expression numerator, Expression denominator);
    Fractions();

    void add(Expression* addend);
    void add(Fractions* addend);

    void subtract(Expression* subtrahend);
    void subtract(Fractions* subtrahend);

    void divide(Expression* dividend);
    void divide(Fractions* dividend);

    void multiply(Expression* multiplicand);
    void multiply(Fractions* multiplicand);

    void simplify();
    int GCDivisor();

    Expression* getNumerator();
    Expression* getDenominator();

    std::string toString();
    double toDecimal();
    std::string getName();

};


#endif /* defined(__calculator__Fractions__) */
