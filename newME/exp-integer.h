#ifndef MATHEXINTEGER_H_INCLUDED
#define MATHEXINTEGER_H_INCLUDED

#include "newME/expression.h"
#include "Constant.h"
#include <iostream>

class MathExInteger : public Constant {
	private:
	    int me_int;

	public:
		MathExInteger();
		MathExInteger(int);
		~MathExInteger();
		Expression add(Expression* addend);
		Expression subtract(Expression* subtrahend);
		Expression multiply(Expression* multiplicand);
		Expression divide(Expression* dividend);

		void simplify();
		int getInt();
		std::string toString();
		std::string getName();
		double toDecimal();
};


#endif // MATHEXINTEGER_H_INCLUDED
