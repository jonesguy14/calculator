#include "Exceptions.h";

Exceptions::Exceptions() {
	this->errorName = "invalid";
	this->errorID = 0;
}

Exceptions::Exceptions(string name) {
	this->errorName = name;
	determineError(errorName);
}

void Exceptions::determineError(string errorName) {

	//Fractional errors
	if (errorName.compare("Cannot divide by zero")) {
		errorID = 1;
	} else if (errorName.compare("Trying to get GCD of non-integer")) {
		errorID = 2;
	} else if (errorName.compare("Denominator is equal to 1, don't need fraction")) {
		errorID = 3;
	} else {
		errorID = 0;
	}

	//Logarithmic errors
	if (errorName.compare("Cannot have the logarithm of a negative number")) {
		errorID = 4;
	} else if (errorName.compare("Cannot have the logarithm of 0")) {
		errorID = 5;
	} else if (errorName.compare("Logarithm is equal to 0")) {
		errorID = 6;
	} else if (errorName.compare("Cannot add logarithms to that data type")) {
		errorID = 7;
	} else if (errorName.compare("Cannot subtract a logarithm from that data type")) {
		errorID = 8;
	} else if (errorName.compare("Cannot divide a logarithm by that data type")) {
		errorID = 9;
	} else if (errorName.compare("Cannot multiply a logarithm by that data type")) {
		errorID = 10;
	} else if (errorName.compare("Simple Logarithm")) {
		errorID = 16;
	} else if (errorName.compare("Evaluable Logarithm")) {
		errorID = 17;
	} else if (errorName.compare("Cannot multiply logarithms")) {
		errorID = 18;
	}else {
		errorID = 0;
	}

	//Integer errors
	if (errorName.compare("Adding integer for non integer, will provide implementation for fractions once they exist")) {
		errorID = 11;
	} else if (errorName.compare("Subbing integer for non integer, will provide implementation for fractions once they exist")) {
		errorID = 12;
	} else if (errorName.compare("Dividing integer for non integer, will provide implementation for fractions once they exist")) {
		errorID = 13;
	} else if (errorName.compare("Multiplying integer by non int")) {
		errorID = 14;
	} else {
		errorID = 0;
	}

	//Mathematical Expression errors
	if (errorName.compare("Operator not recognized")) {
		errorID = 15;
	} else {
		errorID = 0;
	}

	//Other errors

	return errorID;
}

int Exceptions::what() {
	return errorID;
}
