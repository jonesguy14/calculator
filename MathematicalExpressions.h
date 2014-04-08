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
		virtual void add(MathematicalExpression* addend);
		virtual subtract(MathematicalExpression* subtrahend);
		virtual multiply(MathematicalExpression* multiplicand);
		virtual divide(MathematicalExpression* dividend);
		virtual string toString();
};


#endif // MATHEMATICALEXPRESSION_H_INCLUDED
