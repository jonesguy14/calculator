#ifndef E_H_INCLUDED
#define E_H_INCLUDED

#include <iostream>

class E : public Constant {
public:
    E();
    ~E();

    Expression* add(Expression* a);
    Expression* subtract(Expression* s);
    Expression* multiply(Expression* m);
    Expression* divide(Expression* d);

    std::string getName();
    std::string toString();
    double toDecimal();
    MathExInteger* coeffecient;
};

#endif // E_H_INCLUDED
