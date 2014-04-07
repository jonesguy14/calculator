using namespace std;

MathematicalExpression::MathematicalExpression(MathematicalExpression* part1, MathematicalExpression* part2, char op){
	this->part1	=	part1->simplify();
	this->part2	=	part2->simplify();
	
	if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^'){
		this->value	=	this->part1->toString() + " " + op + " " + this->part2->toString();
	}else{
		throw "Operator not recognized";
	}
}

void MathematicalExpression::add(MathematicalExpression* addend){
	addend->simplify();
	string b	=	addend->toString();
	this->value	=	this->value + " " + "+" + " " + b;
}

void MathematicalExpression::subtract(MathematicalExpression* subtrahend){
	subtrahend->simplify();
	string b	=	subtrahend->toString();
	this->value	=	this->value + " " + "-" + " " + b;
}

void MathematicalExpression::multiply(MathematicalExpression* multiplicand){
	multiplicand->simplify();
	string b	=	multiplicand->toString();
	this->value	=	this->value + " " + "*" + " " + b;
}

void MathematicalExpression::divide(MathematicalExpression* dividend){
	dividend->simplify();
	string b	=	dividend->toString();
	this->value	=	this->value + " " + "/" + " " + b;
}

string MathematicalExpression::toString(){
	return this->value;
}
