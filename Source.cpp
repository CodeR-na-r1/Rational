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

	Rational D = b * b - a * c * 4;

	Rational x1 = (-b + D.sqrt()) / 2;
	cout << x1 << endl;

	//Rational x2 = (-b - D.sqrt()) / 2;
	//cout << x2 << endl;

	//cout << "Answer: x1 == " << x1 << ";	x2 == " << x2 << endl;
	system("pause");
	return 0;
}
/*
Пример коэффицентов уравнения:
2 1
-2 1
-4 1

*/