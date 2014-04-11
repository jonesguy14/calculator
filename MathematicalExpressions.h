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
		MathematicalExpression();
		MathematicalExpression(MathematicalExpression* part1, MathematicalExpression* part2, char op);
		MathematicalExpression(int);
		~MathematicalExpression();
		virtual MathematicalExpression add(MathematicalExpression* addend);
		virtual MathematicalExpression subtract(MathematicalExpression* subtrahend);
		virtual MathematicalExpression multiply(MathematicalExpression* multiplicand);
		virtual MathematicalExpression divide(MathematicalExpression* dividend);
		virtual void simplify();
		virtual int getInt();
		virtual std::string toString();
		virtual double toDecimal();
		virtual std::string getName();
};


#endif // MATHEMATICALEXPRESSION_H_INCLUDED
