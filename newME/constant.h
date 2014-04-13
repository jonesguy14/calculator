#ifndef CONSTANT_H_INCLUDED
#define CONSTANT_H_INCLUDED

#include "expression.h"
#include <iostream>

class Constant : public Expression {
public:
    Constant();
    ~Constant();
    virtual void add(Expression* a) = 0;
    virtual void subtract(Expression *s) = 0;
    virtual void multiply(Expression* m) = 0;
    virtual void divide(Expression* d) = 0;
    virtual std::string getName() = 0;
    virtual std::string toString() = 0;
    virtual void negative();
    virtual double toDecimal() = 0;
    virtual Expression* getCoefficient();
};



#endif // CONSTANT_H_INCLUDED
