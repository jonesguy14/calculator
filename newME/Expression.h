#include <vector>

class MathematicalExpression{
	private:
		MathematicalExpression* value;
		boolean initiliazed;
		vector<MathematicalExpression*> addition;
		vector<MathematicalExpression*> multiplication;
		vector<MathematicalExpression*> division;
		vector<MathematicalExpression*> exponentiate;
		
	public:
		MathematicalExpression(MathematicalExpression*);
		
		void add(MathematicalExpression*);
		void subtract(MathematicalExpression*);
		void multiply(MathematicalExpression*);
		void divide(MathematicalExpression*);
		void exponentiate(MathematicalExpression*);
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


