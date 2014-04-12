#include "Decimal.h"

Decimal::Decimal(double decimal) {
	this->value = decimal;
}

MathematicalExpression Decimal::add(MathematicalExpression addend) {
	double decimal = value + addend;
	Decimal result(decimal);
	return result;
}

MathematicalExpression  Decimal::subtract(MathematicalExpression subtrahend) {
	double decimal = value - subtrahend;
	Decimal result(decimal);
	return result;
}

MathematicalExpression  Decimal::divide(MathematicalExpression dividend) {
	double decimal = value / dividend;
	Decimal result(decimal);
	return result;
}

MathematicalExpression  Decimal::multiply(MathematicalExpression multiplcand) {
	double decimal = value * multiplcand;
	Decimal result(decimal);
	return result;
}

MathematicalExpression  Decimal::simplify(double decimal) {
	//But really though...how can you simplify a decimal?
}

string  Decimal::toString(double decimal) {
	toString = "" + toDecimal(decimal);
	return toString;
}

double  Decimal::toDecimal(double decimal) {
	return decimal;
}

Fraction  Decimal::toFraction(double decimal) {
	long intPart = (long) decimal;
	int fractionalPart = decimal - intPart;
	
	
	int numerator = fractionalPart;
	int digits = 0;
	while(fractionalPart > 1) {
		fractionalPart = fractionalPart/10;
		digits++;
	}

	int denominator = pow(10, digits);
	

	toFrac(int numerator, int denominator);
  	Fraction frac((numerator*intPart)/denominator);
  	return frac;
}

Fraction toFrac(int& numerator, int& denominator)
{

  int counter = numerator;

  if ((numerator >= 2) && (denominator >= 2))
  {

    for (counter; counter >= 2; counter--)
    {

      if ((numerator%counter == 0) && (denominator%counter == 0))
      {

        numerator = (numerator/counter);
        denominator = (denominator/counter);
        break;

      }

    }

  }

}
