#include <iostream>
using namespace std;

class shuntingStack {

private:
   int MAX;
   int top;
   char* items;

public:
	shuntingStack(int sizey){
		MAX = sizey;
		top = -1;
		items = new char[MAX];
	}

	~shuntingStack(){ delete [] items; }

	void push(char c){
		if(isFull()){
			cout << "Stack Full!" << endl;
		}

		items[++top] = c;
	}

	char pop(){
		if(isEmpty()){
			cout << "Stack Empty!" << endl;
		}

		return items[top--];
	}

	char getTop() {
        return items[top];
	}

	bool hasItems() {
        if (top>-1) {return true;}
        else return false;
	}

	int isEmpty(){ return top == -1; }

	int isFull(){ return top+1 == MAX; }
};
