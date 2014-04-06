#include <iostream>
using namespace std;

class expressionStack {

private:
   int MAX;
   int top;
   MathematicalExpression* items;

public:
	expressionStack(int size){
		MAX = size;
		top = -1;
		items = new MathematicalExpression[MAX];
	}

	~expressionStack(){ delete [] items; }

	void push(MathematicalExpression expression){
		if(isFull()){
			cout << "Stack Full!" << endl;
			exit(1);
		}

		items[++top] = expression;
	}

	MathematicalExpression pop(){
		if(isEmpty()){
			cout << "Stack Empty!" << endl;
			exit(1);
		}

		return items[top--];
	}

	int isEmpty(){ return top == -1; }

	int isFull(){ return top+1 == MAX; }
};
