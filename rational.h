#pragma once
#include <iostream>
using namespace std;

class Rational
{
public:

	Rational();

	/*explicit*/ Rational(long long int number);

	Rational(long long int number, long long int determinator);

	Rational(const Rational& r);

	Rational operator -() const;

	Rational& operator =(const Rational& r);

	Rational& operator +=(const Rational& r);

	Rational operator +(const Rational& r) const;

	Rational& operator -=(const Rational& r);

	Rational operator -(const Rational& r) const;

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

	Rational operator *(const Rational& r) const;

	Rational& operator /=(const Rational& r);

	Rational operator /(const Rational& r) const;

	Rational& operator *=(const long long int& other);

	Rational operator *(const long long int& other) const;

	friend istream& operator >>(istream& in, Rational& r);

	friend ostream& operator <<(ostream& out, const Rational& r);

	Rational sqrt();

	int getDen();

	int getNum();

private:

	long long int num;

	long long int den;
	
	void Simplify();

	long long int NOD(long long int first, long long int second);
};