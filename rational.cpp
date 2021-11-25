#include "Rational.h"

Rational::Rational()
{
	num = 0;
	den = 1;
}

Rational::Rational(long long int number) :Rational()
{
	num = number;
}

Rational::Rational(long long int number, long long int determinator) :Rational(number)
{
	den = determinator;
}

Rational::Rational(const Rational& r)
{
	num = r.num;
	den = r.den;
}

Rational Rational::operator -() const
{
	Rational rr(-num, den);
	return rr;
}

Rational& Rational::operator =(const Rational& r)
{
	num = r.num;
	den = r.den;
	return *this;
}

Rational& Rational::operator +=(const Rational& r)
{
	num = num * r.den + r.num * den;
	den *= r.den;
	Simplify();
	return	*this;
}

Rational Rational::operator +(const Rational& r)const
{
	Rational res(num, den);
	res += r;
	return res;
}

Rational& Rational::operator -=(const Rational& r)
{
	return this->operator+=(r.operator-());
}

Rational Rational::operator -(const Rational& r)const
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
	return ((num == r.num) && (den == r.den));
}

bool Rational::operator !=(const Rational& r) const
{
	return !(this->operator==(r));
}

bool Rational::operator >=(const Rational& r) const	//Операция сравнения применима к дробям с любыми знаменателями (разными)
{
	return num * r.den >= r.num * den;
}

bool Rational::operator <=(const Rational& r) const
{
	return num * r.den <= r.num * den;
}

bool Rational::operator >(const Rational& r) const
{
	return num * r.den > r.num * den;
}

bool Rational::operator <(const Rational& r) const
{
	return num * r.den < r.num * den;
}

Rational& Rational::operator *=(const Rational& r)
{
	num = num * r.num;
	den = den * r.den;
	Simplify();
	return *this;
}

Rational Rational::operator *(const Rational& r) const
{
	Rational res(num, den);
	res *= r;
	return res;
}

Rational& Rational::operator /=(const Rational& r)
{
	num *= r.den;
	den *= r.num;
	Simplify();
	return *this;
}

Rational Rational::operator /(const Rational& r) const
{
	Rational res(num , den);
	res /= r;
	return res;
}

Rational& Rational::operator *=(const long long int& other)
{
	num *= other;
	Simplify();
	return *this;
}

Rational Rational::operator *(const long long int& other) const
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

	long long int temp;

	while ((temp = this->NOD(abs(num), abs(den))) != 1)
	{
		num /= temp;
		den /= temp;
	}
	return;
}

Rational Rational::sqrt()
{
	double res_double = (double)num / den;	// Перевод Rational в double

	res_double = std::sqrt(res_double);	// Берем корень из double

	long long res_int = *(long long*)(&res_double);	// Приводим адрес к long long и сохраняем в переменную long long

	int E = (int)((res_int >> 52) & 0x07FF);	// Достаем порядок из нашего числа ( [52..62] биты )
	E -= 1023;	// Убираем смещение из порядка

	long long M = res_int & 0x0FFFFFFFFFFFFF;	// Достаем мантиссу из числа ( [0..51] биты )

	M = M | 0x010000000000000;	// Ставим 53 бит мантиссы, который не хранится в числе,но подразумевается (так как всегда единица)

	Rational res;

	res.num = E >= 0 ? M << E : M >> (-E);	// Если порядок положительный, смещаем биты влево, иначе вправо. ( убираем нормализованную форму числа)

	res.den = 1LL << 52;	// Соответствующий к числителю знаменатель

	res.Simplify();	// Упрощаем

	return res;
}

long long int Rational::NOD(long long int first, long long int second)
{
	while ((first != 0) && (second != 0))
	{
		if (first > second)
			first %= second;
		else
			second %= first;
	}
	return  first + second;
}

int Rational::getDen()
{
	return this->den;
}

int Rational::getNum()
{
	return (*this).num;
}
