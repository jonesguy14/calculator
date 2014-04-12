#ifndef CONSTANT_H_INCLUDED
#define CONSTANT_H_INCLUDED

#include "Expression.h"
#include <iostream>

class Constant : public Expression {
public:
    Constant();
    ~Constant();
    virtual Expression add(Expression* a) = 0;
    virtual Expression subtract(Expression *s) = 0;
    virtual Expression multiply(Expression* m) = 0;
    virtual Expression divide(Expression* d) = 0;
    virtual std::string getName() = 0;
    virtual std::string toString() = 0;
    virtual double toDecimal() = 0;
};



#endif // CONSTANT_H_INCLUDED
