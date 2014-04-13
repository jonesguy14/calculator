#ifndef EULERS_H_INCLUDED
#define EULERS_H_INCLUDED

#include "constant.h"
#include "exp-integer.h"
#include <iostream>

class Eulers : public Constant {
public:
    Eulers();
    ~Eulers();

    void add(Expression* a);
    void subtract(Expression* s);
    void multiply(Expression* m);
    void divide(Expression* d);

    std::string getName();
    std::string toString();
    double toDecimal();
    MathExInteger* coefficient;
};

#endif // EULERS_H_INCLUDED
