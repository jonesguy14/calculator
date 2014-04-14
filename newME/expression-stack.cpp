#include <iostream>
#include "expression.h"

using namespace std;

class expressionStack {

private:
   int MAX;
   int top;
   Expression** items;

public:
	expressionStack(int size){
		MAX = size;
		top = -1;
		Expression *items[MAX];
	}

	~expressionStack(){ delete [] items; }

	void push(Expression* expression){
		if(isFull()){
			cout << "Stack Full!" << endl;
		}

		items[++top] = expression;
	}

	Expression* pop(){
		if (isEmpty()){
			throw "Error with input! Operator to term ratio does not match up.";
		}
        else {
            return items[top--];
        }
	}

	Expression* getTop() {
        return items[top];
	}

	bool hasItems() {
        if (top>-1) {return true;}
        else return false;
	}

	int isEmpty(){ return top == -1; }

	int isFull(){ return top+1 == MAX; }
};
