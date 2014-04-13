#ifndef MATHEXINTEGER_H_INCLUDED
#define MATHEXINTEGER_H_INCLUDED

#include "expression.h"
#include "constant.h"
#include <iostream>

class MathExInteger : public Constant {
	private:
	    int me_int;

	public:
		MathExInteger();
		MathExInteger(int);
		~MathExInteger();
		void add(Expression* addend);
		void subtract(Expression* subtrahend);
		void multiply(Expression* multiplicand);
		void divide(Expression* dividend);

		void simplify();
		int getInt();
		std::string toString();
		std::string getName();
		double toDecimal();
};


#endif // MATHEXINTEGER_H_INCLUDED
