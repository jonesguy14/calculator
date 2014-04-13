#ifndef PI_H_INCLUDED
#define PI_H_INCLUDED

#include "constant.h"
#include <iostream>

class Pi : public Constant {
public:
    Pi();
    ~Pi();

    Expression* add(Expression* a);
    Expression* subtract(Expression* s);
    Expression* multiply(Expression* m);
    Expression* divide(Expression* d);

    std::string getName();
    std::string toString();
    double toDecimal();
    MathExInteger* coeffecient;
};


#endif // PI_H_INCLUDED
