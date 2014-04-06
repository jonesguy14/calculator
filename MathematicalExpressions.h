#ifndef MATHEMATICALEXPRESSION_H_INCLUDED
#define MATHEMATICALEXPRESSION_H_INCLUDED

class MathematicalExpression{
	private:
		MathematicalExpression* part1;
		MathematicalExpression* part2;
		char op;
		string value;

	public:
		MathematicalExpression(MathematicalExpression* part1, MathematicalExpression* part2, char op);
		void add(MathematicalExpression* addend);
		void subtract(MathematicalExpression* subtrahend);
		void multiply(MathematicalExpression* multiplicand);
		void divide(MathematicalExpression* dividend);
		string toString();
};


#endif // MATHEMATICALEXPRESSION_H_INCLUDED
