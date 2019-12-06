#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <cstdlib>
#include <iosfwd>
#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <unistd.h>


// Mathematical helper functions.
//
// NOTE: These are defined in rational.cpp.
int gcd(int, int);
int lcm(int, int);


// Represents a rational number. The rational numbers are the set of
// numbers that can be represented as the quotient of two integers.
class Rational
{

public:

	Rational();
	Rational(int);
	Rational(int, int);
	Rational(const Rational&);
	int num() const { return numerator; }// Returns the numerator.
	int den() const { return denominator; }// Returns the denominator
	void print(); // prints the fraction in num/denom form.
	double printd(bool); // prints the fraction as a decimal and returns that value. Bool parameter is for weather or not to cout the result.
	double printd(); // overloaded printd to assume that the result should be printed to cout.

	void operator=(const Rational);
	void operator=(int);
	bool operator==(Rational);
	bool operator!=(Rational&);
	bool operator<(Rational);
	bool operator<=(Rational&);
	bool operator>(Rational&);
	bool operator>=(Rational&);

    friend bool operator==(int , Rational);
    friend bool operator<(int, Rational);

	Rational operator+(const Rational&);
	Rational operator+(int);
	Rational operator-(const Rational&);
	Rational operator-(int);
	Rational operator*(const Rational&);
	Rational operator*(int);
	Rational operator/(const Rational&);
	Rational operator/(int);

private:
	int numerator;
	int denominator;

};

std::ostream& operator<<(std::ostream&, Rational);
std::istream& operator>>(std::istream&, Rational&);

#endif
