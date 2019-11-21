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
	string str1 = "5+(5-4)^2.5/(2.5-8*2)";
	string str2 = "-5+6";
	c.SetExpr(str1);
	string test = c.ToPostfix();
	cout << str1 << " = " << test << endl;
	double res = c.OpCalc();
	cout << endl << str1 << " = " << res << endl;
	c.SetExpr(str2);
	res = c.Calc();
	cout << endl << str2 << " = " << res << endl;
	//.......................................................//
	system("pause");
	return 0;
}