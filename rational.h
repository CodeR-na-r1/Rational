#pragma once
#include <iostream>
using namespace std;

class Rational
{
public:

	Rational();

	/*explicit*/ Rational(int number);

	Rational(int number, int determinator);

	Rational& operator -() const;

	Rational& operator =(const Rational& r);

	Rational& operator +=(const Rational& r);

	Rational& operator +(const Rational& r) const;

	Rational& operator -=(const Rational& r);

	Rational& operator -(const Rational& r) const;

	Rational& operator ++();

	Rational operator ++(int);
	
	Rational& operator --();
	
	Rational operator --(int);
	
	bool operator ==(const Rational& r) const;

	bool operator !=(const Rational& r) const;

	bool operator >=(const Rational& r) const;

	bool operator <=(const Rational& r) const;

	bool operator >(const Rational& r) const;

	bool operator <(const Rational& r) const;

	Rational& operator *=(const Rational& r);

	Rational& operator *(const Rational& r) const;

	Rational& operator /=(const Rational& r);

	Rational& operator /(const Rational& r) const;

	Rational& operator *=(const int& other);

	Rational& operator *(const int& other) const;

	friend istream& operator >>(istream& in, Rational& r);

	friend ostream& operator <<(ostream& out, const Rational& r);

	friend Rational& sqrt(const Rational& r);

private:

	long long int num;
	long long int den;
	
	void Simplify();
};

Rational& sqrt(const Rational& r);