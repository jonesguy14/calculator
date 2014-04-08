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
		virtual void add(MathematicalExpression* addend);
		virtual void subtract(MathematicalExpression* subtrahend);
		virtual void multiply(MathematicalExpression* multiplicand);
		virtual void divide(MathematicalExpression* dividend);
		virtual void simplify();
		virtual std::string toString();
};


#endif // MATHEMATICALEXPRESSION_H_INCLUDED
