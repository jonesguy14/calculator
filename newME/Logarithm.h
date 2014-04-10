#include "Expression.h"
#include <iostream>

class Logarithm : public Expression{
	private:
		Expression base;
		Expression argument;
		
	public:
		Logarithm(Expression, Expression);
		Logarithm(Expression, Exponent); // Check if base == Exponent.base, throws error: Simple logarithm
		Logarithm(Integer, Integer); // If evaluates to a clean number, throws error: Simple expression
		
		void add(Expression*); // Throws error: Cannot add expression to logarithm
		void subtract(Expression*); // Throws error: Cannot subtract expression from logarithm
		void multiply(Expression*); // Throws error: Cannot multiply expression with logarithm
		void multiply(Logarithm*); // Throws error: Cannot multiply logarithms
		void divide(Expression*); // Throws error: Cannot divide logarithm by expression
		
		void add(Logarithm*);
		void subtract(Logarithm*);
		void divide(Logarithm*);
		
		void simplify();
		std::string toString();
		double toDecimal();
}
