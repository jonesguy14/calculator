#ifndef MATHEMATICALEXPRESSION_H_INCLUDED
#define MATHEMATICALEXPRESSION_H_INCLUDED
#include <iostream>

class MathematicalExpression{
	private:
		MathematicalExpression* part1;
		MathematicalExpression* part2;
		char op;
		std::string value;

	public:
		MathematicalExpression(MathematicalExpression* part1, MathematicalExpression* part2, char op);
		MathematicalExpression(int);
		virtual MathematicalExpression add(MathematicalExpression* addend);
		virtual MathematicalExpression subtract(MathematicalExpression* subtrahend);
		virtual MathematicalExpression multiply(MathematicalExpression* multiplicand);
		virtual MathematicalExpression divide(MathematicalExpression* dividend);
		virtual MathematicalExpression simplify();
		virtual std::string toString();
};


#endif // MATHEMATICALEXPRESSION_H_INCLUDED
