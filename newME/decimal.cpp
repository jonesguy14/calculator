#include "Decimal.h"

Decimal::Decimal(double decimal) {
	this->value = decimal;
}

void Decimal::add(Expression addend) {
	double decimal = value + addend;
	Decimal result(decimal);
	return result;
}

void Decimal::subtract(Expression subtrahend) {
	double decimal = value - subtrahend;
	Decimal result(decimal);
	return result;
}

void Decimal::divide(Expression dividend) {
	double decimal = value / dividend;
	Decimal result(decimal);
	return result;
}

void Decimal::multiply(Expression multiplcand) {
	double decimal = value * multiplcand;
	Decimal result(decimal);
	return result;
}

void  Decimal::simplify(double decimal) {
	//But really though...how can you simplify a decimal?
}

string  Decimal::toString(double decimal) {
	toString = "" + toDecimal(decimal);
	return toString;
}

double  Decimal::toDecimal(double decimal) {
	return decimal;
}

Fraction Decimal::toFraction(double decimal) {
	long intPart = (long) decimal;
	int fractionalPart = decimal - intPart;

	int digits = 0;
	while(fractionalPart > 0.00001) {
		fractionalPart = fractionalPart*10;
		digits++;
		fractionalPart = fractionalPart - (int)fractionalPart;
	}


	int denominator = pow(10, digits);
	int numerator = (fractionalPart*denominator);


	toFrac(int numerator, int denominator);
  	Fraction frac((numerator*intPart)/denominator);
  	return frac;
}

void toFrac(int& num, int denom)
{
  if ((num >= 2) && (denom >= 2)){
	for (int i = num; i >= 2; i--) {
		 if ((num%i == 0) && (denom%i == 0)) {
		 	num = (num/i);
        		denom = (denom/i);
        	}
	 }
    }
    
    numerator = num;
    denominator = denom;

}
