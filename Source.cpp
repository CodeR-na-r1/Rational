#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
	cout << "###\nexample in:\n123 12\nfirst num - numerator and second num - denominator\n###\n" << endl;

	Rational a, b, c;
	cout << "Enter coefficient a: " << endl;
	cin >> a;
	cout << "Enter coefficient b: " << endl;
	cin >> b;
	cout << "Enter coefficient c: " << endl;
	cin >> c;

	Rational x1, x2;

	Rational D = b * b - a * c * 4;

	x1 = (-b + sqrt(D)) / 2;
	x2 = (-b - sqrt(D)) / 2;

	cout << "Answer: x1 == " << x1 << ";	x2 == " << x2 << endl;

	return 0;
}