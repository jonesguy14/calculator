#ifndef MATHEXINTEGER_H_INCLUDED
#define MATHEXINTEGER_H_INCLUDED

#include "MathematicalExpressions.h"
#include <iostream>

class MathExInteger : public MathematicalExpression {
	private:
	    int me_int;

	public:
		MathExInteger();
		MathExInteger(int);
		//~MathExInteger();
		MathematicalExpression add(MathExInteger* addend);
		MathematicalExpression add(MathematicalExpression* addend);

		MathematicalExpression subtract(MathExInteger* subtrahend);
		MathematicalExpression subtract(MathematicalExpression* subtrahend);

		MathematicalExpression multiply(MathematicalExpression* multiplicand);
		MathematicalExpression multiply(MathExInteger* multipicand);

		MathematicalExpression divide(MathExInteger* dividend);
		MathematicalExpression divide(MathematicalExpression* dividend);

		void simplify();
		int getInt();
		std::string toString();
		std::string getName();//if base.getName() == "Integer"
};


#endif // MATHEXINTEGER_H_INCLUDED
