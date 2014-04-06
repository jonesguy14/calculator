#include "MathematicalExpression.h"

class logarithm : public MathematicalExpression{
	private:
		MathematicalExpression base;
		MathematicalExpression exponent;

	public:
		Logarithm(MathematicalExpression base, MathematicalExpression exponent);
		void add(Logarithm* addend);
		void add(MathematicalExpression* addend);
		
		void subtract(Logarithm* subtrahend);
		void subtract(MathematicalExpression* subtrahend);
		
		void multiply(MathematicalExpression* multiplicand);
		
		void divide(Logarithm* dividend);
		void divide(MathematicalExpression* dividend);
		
		void simplify();
		MathematicalExpression getBase();
		MathematicalExpression getExponent();
		string toString();
};
