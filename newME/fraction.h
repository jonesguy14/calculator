#ifndef __calculator__Fractions__
#define __calculator__Fractions__

#include <iostream>
#include "MathematicalExpressions.h"


class Fractions : public MathematicalExpression{
private:

public:
    MathematicalExpression numerator;
    MathematicalExpression denominator;

    Fractions(MathematicalExpression* numerator, MathematicalExpression* denominator);
    Fractions();

    MathematicalExpression add(MathematicalExpression* addend);
    MathematicalExpression add(Fractions* addend);

    MathematicalExpression subtract(MathematicalExpression* subtrahend);
    MathematicalExpression subtract(Fractions* subtrahend);

    MathematicalExpression divide(MathematicalExpression* dividend);
    MathematicalExpression divide(Fractions* dividend);

    MathematicalExpression multiply(MathematicalExpression* multiplicand);
    MathematicalExpression multiply(Fractions* multiplicand);

    void simplify();
    int GCDivisor();

    std::string toString();
    double toDecimal();
    std::string getName();

};


#endif /* defined(__calculator__Fractions__) */
