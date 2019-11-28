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
	try
	{
		TStack<int> a;
		TCalculator c;
		string str1 = "-5+8";
		string str2 = "-5+6";
		c.SetExpr(str1);
		string test = c.ToPostfix();
		cout << str1 << " = " << test << endl;
		double res = c.Calc();
		cout << endl << str1 << " = " << res << endl;
		c.SetExpr(str2);
		res = c.OldCalc();
		cout << endl << str2 << " = " << res << endl;
	}
	catch (int err)
	{
		if (err == 3)
		{
			cout << endl << "-----error-----" << endl;
		}
	}
	//.......................................................//
	system("pause");
	return 0;
}