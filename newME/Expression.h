#include <vector>

class Expression{
	private:
		Expression* value;
		boolean initiliazed;
		vector<Expression*> addition;
		vector<Expression*> multiplication;
		vector<Expression*> division;
		vector<Expression*> exponentiate;
		
	public:
		Expression(Expression*);
		
		void add(Expression*);
		void subtract(Expression*);
		void multiply(Expression*);
		void divide(Expression*);
		void exponentiate(Expression*);
		void simplify();
		std::string toString();
}

/*

Logarithm L(2, 6); // log_2:6
Logarithm L2(2, 3); // log_2:3
L.add(&L2);
L.toString() // log_2:18

Exponent E (4, L);
throw exception

catch:
	MathematicalExpression M1(4);
	M1.exponentiate(L);
	// M1.exponentiate[0] == 4  
	// M1.exponentiate[1] == log_2:18
	
L.add(&M1);
throw exception

catch:
	M1.add(&L);
	M1.toString(); // 4^log_2:18 + log_2:18;

log_2:6 + 3^7 - 5^7
*/


