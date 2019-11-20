#include <iostream>
#include <cstdlib>
#include <clocale>
#include "Stack.h"
#include "TCalculator.h"
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	//.......................................................//
	TStack<int> a;
	TCalculator c;
	string str = "5+(5-4)^2.5/(2.5-8)";
	c.SetExpr(str);
	string test = c.ToPostfix();
	cout << str << " = " << test << endl;
	double res = c.Calc();
	cout << endl << str << " = " << res << endl;
	//.......................................................//
	system("pause");
	return 0;
}