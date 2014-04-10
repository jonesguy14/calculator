#ifndef MATHEXINTEGER_H_INCLUDED
#define MATHEXINTEGER_H_INCLUDED

#include "MathematicalExpressions.h"
#include <iostream>

class MathExInteger : public MathematicalExpression{
	private:
	    int me_int;

	public:
		MathExInteger(int);
		MathematicalExpression add(MathExInteger* addend);
		MathematicalExpression add(MathematicalExpression* addend);

		MathematicalExpression subtract(MathExInteger* subtrahend);
		MathematicalExpression subtract(MathematicalExpression* subtrahend);

		MathematicalExpression multiply(MathematicalExpression* multiplicand);
		MathematicalExpression multiply(MathExInteger* multipicand);

		MathematicalExpression divide(MathExInteger* dividend);
		MathematicalExpression divide(MathematicalExpression* dividend);

		MathematicalExpression simplify();
		int getInt();
		std::string toString();
};


#endif // MATHEXINTEGER_H_INCLUDED
