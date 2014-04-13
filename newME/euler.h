#ifndef EULERS_H_INCLUDED
#define EULERS_H_INCLUDED

#include "constant.h"
#include <iostream>

class Eulers : public Constant {
public:
    Eulers();
    ~Eulers();

    Expression* add(Expression* a);
    Expression* subtract(Expression* s);
    Expression* multiply(Expression* m);
    Expression* divide(Expression* d);

    std::string getName();
    std::string toString();
    double toDecimal();
    MathExInteger* coeffecient;
};

#endif // EULERS_H_INCLUDED
