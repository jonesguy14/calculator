#include <iostream>
using namespace std;

class intStack {

private:
   int MAX;
   int top;
   int* items;

public:
	intStack(int sizey){
		MAX = sizey;
		top = -1;
		items = new int[MAX];
	}

	~intStack(){ delete [] items; }

	void push(int n){
		if(isFull()){
			cout << "Stack Full!" << endl;
		}

		items[++top] = n;
	}

	int pop(){
		if(isEmpty()){
			cout << "Stack Empty!" << endl;
		}

		return items[top--];
	}

	int getTop() {
        return items[top];
	}

	bool hasItems() {
        if (top>-1) {return true;}
        else return false;
	}

	int isEmpty(){ return top == -1; }

	int isFull(){ return top+1 == MAX; }
};
