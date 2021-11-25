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
	
	if (D < 0)
	{

		cout << "no solutions" << endl;

	}
	else if (D == 0)
	{

		cout << "x == " << ((-b) / (a * 2)) << endl;

	}
	else if (D > 0)
	{
		Rational x1 = (-b + D.sqrt()) / (a * 2);

		Rational x2 = (-b - D.sqrt()) / (a * 2);

		cout << "Answer: x1 == " << x1 << ";	x2 == " << x2 << endl;
	}

	system("pause");
	return 0;
}
/*
Пример коэффицентов уравнения:
6 1
5 1
4 1
Ответ: Нет корней


2 1
-2 1
-4 1
Ответ: 2 и -1


4 1
4 1
1 1
Ответ: -0.5
*/