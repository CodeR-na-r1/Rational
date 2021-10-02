#include "Rational.h"

Rational::Rational()
{
	num = 0;
	den = 1;
}

Rational::Rational(int number) :Rational()
{
	num = number;
}

Rational::Rational(int number, int determinator) :Rational(number)
{
	den = determinator;
}

Rational& Rational::operator -() const
{
	Rational rr(-num, den);
	return rr;
}

Rational& Rational::operator =(const Rational& r)
{
	num = r.num;
	den = r.den;
}

Rational& Rational::operator +=(const Rational& r)
{
	num = num * r.den + r.num * den;
	den *= r.den;
	Simplify();
	return	*this;
}

Rational& Rational::operator +(const Rational& r) const
{
	Rational res(num, den);
	res += r;
	res.Simplify();
	return res;
}

Rational& Rational::operator -=(const Rational& r)
{
	return this->operator+=(r.operator-());
}

Rational& Rational::operator -(const Rational& r) const
{
	return this->operator+(r.operator-());
}

Rational& Rational::operator++()
{
	num += den;
	return *this;
}

Rational Rational::operator++(int)
{
	Rational res(*this);
	num += den;
	return res;
}

Rational& Rational::operator--()
{
	num -= den;
	return *this;
}

Rational Rational::operator--(int)
{
	Rational res(*this);
	num -= den;
	return *this;
}

bool Rational::operator ==(const Rational& r) const
{
	return (num == r.num) && (den == r.num);
}

bool Rational::operator !=(const Rational& r) const
{
	return !(this->operator==(r));
}

bool Rational::operator >=(const Rational& r) const	//Логика может немного поменятся, надо сравнивать произведения числ и знаменателей 1 и 2 дробей соответсвенно (92-110 строгки)
{
	return (num >= r.num) && (den == r.num);
}

bool Rational::operator <=(const Rational& r) const
{
	return (num <= r.num) && (den == r.den);
}

bool Rational::operator >(const Rational& r) const
{
	return (num > r.num) && (den == r.num);
}

bool Rational::operator <(const Rational& r) const
{
	return (num < r.num) && (den == r.den);
}

Rational& Rational::operator *=(const Rational& r)
{
	num = num * r.num;
	den = den * r.den;
	Simplify();
	return *this;
}

Rational& Rational::operator *(const Rational& r) const
{
	Rational res(num, den);
	res *= r;
	return res;
}

Rational& Rational::operator /=(const Rational& r)
{
	num *= r.den;
	den *= r.num;
	return *this;
}

Rational& Rational::operator /(const Rational& r) const
{
	Rational res(num , den);
	res /= r;
	return res;
}

Rational& Rational::operator *=(const int& other)
{
	num *= other;
	Simplify();
	return *this;
}

Rational& Rational::operator *(const int& other) const
{
	Rational res(num, den);
	res *= other;
	return res;
}

istream& operator >>(istream& in, Rational& r)
{
	in >> r.num >> r.den;
	return in;
}

ostream& operator <<(ostream& out, const Rational& r)
{
	out << double(r.num) / double(r.den);
	return out;
}

void Rational::Simplify()
{
	if (den < 0)
	{
		num = -num;
		den = -den;
	}

	for (int i = 2; i <= abs(num) && i <= abs(den); i++)
	{
		if (num % i == 0 && den % i == 0)
		{
			num /= i;
			den /= i;
			i--;
		}
	}
}

Rational& sqrt(const Rational& r)
{
	Rational res(r.num, r.den);
	
	double res_double = r.num / r.den;

	res_double = sqrt(res_double);

	long long res_int = *(long long*)(&res_double);

	int E = (int)((res_int >> 52) & 0x07FF);
	E -= 1023;

	long long M = res_int & 0x0FFFFFFFFFFFFF;



	return res;
}