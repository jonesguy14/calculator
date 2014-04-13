#ifndef __calculator__Fractions__
#define __calculator__Fractions__

#include <iostream>
#include "expression.h"


class Fractions : public Expression{
private:

public:
    Expression numerator;
    Expression denominator;

    Fractions(Expression* numerator, Expression* denominator);
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

    std::string toString();
    double toDecimal();
    std::string getName();

};


#endif /* defined(__calculator__Fractions__) */
