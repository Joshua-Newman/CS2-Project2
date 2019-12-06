
#include "Rational.hpp"
#include <cassert>
#include <iomanip>
#include <iostream>
#include <unistd.h>


namespace
{
  using std::cerr;
  using std::cout;
  using std::endl;
}


// -------------------------------------------------------------------------- //
// Helper functions

// Compute the GCD (greatest common divider) of two integer values using
// Euclid's algorithm.
int gcd(int a, int b) {
	a = abs(a); // make them to be positive numbers
	b = abs(b);
	if (a == 0 || b == 0) // if one number is 0, always return 1
	{
		return 1;
	}
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

// Compute the LCM (Least Common Multiple) of two integer values.
int lcm(int a, int b) {
	a = abs(a); // make them positive
	b = abs(b);
	if (a == 0 || b == 0) {
		throw "Integers can not be zero in calculating Least Common Multiple";
	}
	return (abs(a) / gcd(a, b)) * abs(b);
}

// -------------------------------------------------------------------------- //
// Rational implementation

std::ostream &operator<<(std::ostream &os, Rational r) {
	return os << r.num() << '/' << r.den();
}

// DO NOT CHANGE operators >> overloading function
std::istream &operator>>(std::istream &is, Rational &r) {
	// Read the first integer, return on error.
	int p;
	is >> p;
	if (!is)
		return is;

	// Check for the divider. Assuming no spaces.
	if (is.peek() != '/') {
		r = Rational(p);
		return is;
	}
	is.get();

	int q;
	is >> q;
	if (!is)
		return is;
	if (q == 0) {
		is.setstate(std::ios::failbit);
		return is;
	}
	r = Rational(p, q);
	return is;
#if 0
	int p, q;
	char c;
	is >> p >> c >> q;
	if (!is)
		return is;
	// Require that the divider to be a '/'.
	if (c != '/') {
		is.setstate(std::ios::failbit);
		return is;
	}

	// Make sure that we didn't read p/0.

	r = Rational(p, q);
	return is;
#endif
}

Rational::Rational() // default constructor
{
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int n) // constructor taking 1 integer as numerator / 1
{
	numerator = n;
	denominator = 1;
}

Rational::Rational(	int n,	int d) // constructor taking 2 integers as numerator / denominator.
{
	if (d == 0) {
		cerr << "Denominator cannot equal 0.\n";
		numerator = 0;
		denominator = 1;
	} else {
		if (d < 0) // fix the signs
		{
			n *= -1;
			d *= -1;
		}
		int com = gcd(n, d);
		if (com > 1) // reduce the fraction
		{
			n = n / com;
			d = d / com;
		}
		numerator = n;
		denominator = d;
	}
}

Rational::Rational(const Rational &obj) // copy constructor
{
	numerator = obj.numerator;
	denominator = obj.denominator;
}

void Rational::print() // Print Function
{
	cout << numerator << " / " << denominator << endl;
}

double Rational::printd(bool output) // Print function that uses a bool
{
	if (numerator == denominator) // Any number / the same number = 1
	{
		if (output == true)
			cout << "1\n" << endl;
		return 1;
	}
	else if (numerator == 0) // If numerator = 0, the number is always 0.
	{
		if (output == true)
			cout << "0\n";
		return 0;
	}
	else if (denominator == 1) // If denominator = 1, the number is always just the numerator.
	{
		if (output == true)
			cout << numerator << endl;
		return numerator;
	}
	else if (gcd(numerator, denominator) == 1)
    {
		if (output == true)
		{
			cout << numerator / static_cast<double>(denominator)
				 << endl; // Converts the fraction to a double decimal.
		}
		return numerator / static_cast<double>(denominator);
	}
	else
	  {
		  if (output == true)
          {
			  cout << numerator << " / " << denominator << endl;
          }
		  return numerator / static_cast<double>(denominator);
	  }
}

double Rational::printd() // Overloading the printd function
{
	if (numerator == denominator)
    {
		cout << "1\n" << endl;
		return 1;
	}
	else if (numerator == 0)
	{
		cout << "0\n";
		return 0;
	}
	else if (denominator == 1)
    {
		cout << numerator << endl;
		return numerator;
	}
	else if (gcd(numerator, denominator) == 1)
    {
		cout << numerator / static_cast<double>(denominator) << endl;
		return numerator / static_cast<double>(denominator);
	}
	else
    {
		cout << numerator << " / " << denominator << endl;
		return numerator / static_cast<double>(denominator);
	}
}

void Rational::operator=(const Rational R) // assignment operator overloading
{
	numerator = R.numerator;
	denominator = R.denominator;
}

void Rational::operator=(int I) // assignment operator overloading
{
	numerator = I;
	denominator = 1;
}

bool Rational::
operator==(Rational R) // equal to comparison operator overloading
{
	if (this->printd(false) == R.printd(false))
    {
		return true;
	}
	else
    {
		return false;
	}
}

bool Rational::operator!=(Rational &R) // not equal to comparison operator overloading
{
	if (this->printd(false) != R.printd(false))
    {
		return true;
	}
	else
	{
		return false;
	}
}

bool Rational::operator<(Rational R) // less than comparison operator overloading
{
	if (this->printd(false) < R.printd(false))
    {
		return true;
	}
	else
	{
		return false;
	}
}

bool operator==(int x, Rational R) // comparison operator handling integer and rational object
{
	int intR = R.numerator / R.denominator;
	return (x == intR);
}

bool operator<(int x, Rational R) //Less than operator handling integer and rational object
{
	int intR = R.numerator / R.denominator;
	return (x < intR);
}

bool Rational::operator<=(Rational &R) // less than or equal to comparison operator
{
	if (this->printd(false) <= R.printd(false))
    {
		return true;
	}
	else
	{
		return false;
	}
}

bool Rational::operator>(Rational &R) // greater than comparison operator overloading
{
	if (this->printd(false) > R.printd(false))
    {
		return true;
	} else
	{
		return false;
	}
}

bool Rational::operator>=(Rational &R) // greater than or equal to comparison operator overloading
{
	if (this->printd(false) >= R.printd(false))
    {
		return true;
	}
	else
	{
		return false;
	}
}

Rational Rational::operator+(const Rational &R) // addition with 2 rationals
{
	int newNum = (this->numerator * R.denominator + this->denominator * R.numerator);
	int newDen = (this->denominator * R.denominator);
	Rational Sum(newNum, newDen);
	return Sum;
}
Rational Rational::operator+(int I) // addition with rational and an integer
{
	Rational R(I, 1);
	int newNum = (this->numerator * R.denominator + this->denominator * R.numerator);
	int newDen = (this->denominator * R.denominator);
	Rational Sum(newNum, newDen);
	return Sum;
}

Rational Rational::operator-(const Rational &R) // subtraction with 2 rationals
{
	int newNum = (this->numerator * R.denominator - this->denominator * R.numerator);
	int newDen = (this->denominator * R.denominator);
	Rational Dif(newNum, newDen);
	return Dif;
}

Rational Rational::operator-(int I) // subtraction with rational and an integer
{
	Rational R(I, 1);
	int newNum = (this->numerator * R.denominator - this->denominator * R.numerator);
	int newDen = (this->denominator * R.denominator);
	Rational Dif(newNum, newDen);
	return Dif;
}

Rational Rational::operator*(const Rational &R) // multiplication with 2 rationals
{
	int newNum = (this->numerator * R.numerator);
	int newDen = (this->denominator * R.denominator);
	Rational Prod(newNum, newDen);
	return Prod;
}

Rational Rational::operator*(int I) // multiplication with 2 rationals and an integer
{
	Rational R(I, 1);
	int newNum = (this->numerator * R.numerator);
	int newDen = (this->denominator * R.denominator);
	Rational Prod(newNum, newDen);
	return Prod;
}

Rational Rational::operator/(const Rational &R) // division with 2 rationals
{
	Rational Div(R.denominator, R.numerator);
	Div = Div * *this;
	return Div;
}

Rational Rational::operator/(int I) // division with 2 rationals and an integer
{
	Rational Div(1, I);
	Div = Div * *this;
	return Div;
}
