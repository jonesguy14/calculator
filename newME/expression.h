#ifndef EXPRESSION_H_INCLUDED
#define EXPRESSION_H_INCLUDED

#include <vector>
#include <iostream>

class Expression{
	private:
		Expression* value;
		bool initialized;
		std::vector<Expression*> addition;
		std::vector<Expression*> multiplication;

	public:
		Expression(Expression*);
		Expression(std::vector<Expression*>);
		Expression();
		~Expression();

		void add(Expression*);
		void subtract(Expression*);
		void multiply(Expression*);
		void divide(Expression*);
		void exponentiate(Expression*);
		void negative();
		void add_simplify(std::vector<Expression*>);
		void multiply_simplify(std::vector<Expression*>);
		void simplify();

		std::string toString();
		std::string getName();
		int getInt();
};

#endif // EXPRESSION_H_INCLUDED
