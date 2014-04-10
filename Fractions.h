#ifndef __calculator__Fractions__
#define __calculator__Fractions__

#include <iostream>
#include "MathematicalExpressions.h"
using namespace std;


class Fractions : public MathematicalExpression{
private:
    MathematicalExpression numerator;
    MathematicalExpression denominator;
    void GCD(Fractions F1, Fractions F2);
    
public:
    Fractions(MathematicalExpression numerator, MathematicalExpression denominator);
    
    MathematicalExpression add(MathematicalExpression* addend);
    MathematicalExpression add(Fractions* addend);
    
    MathematicalExpression subtract(MathematicalExpression* subtrahend);
    MathematicalExpression subtract(Fractions subtrahend);
    
    MathematicalExpression divide(MathematicalExpression* dividend);
    MathematicalExpression divide(Fractions* dividend);
    
    MathematicalExpression multiply(MathematicalExpression* multiplicand);
    MathematicalExpression multiply(Fractions* multiplicand);
    
    void simplify();
    int GCDivisor();
    int temp1 = 2;
    
    std::string toString();
    double toDecimal();
    
};


#endif /* defined(__calculator__Fractions__) */
