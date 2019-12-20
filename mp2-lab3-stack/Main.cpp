#include <iostream>
#include <cstdlib>
#include <clocale>
#include "TCalculator.h"
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	//.......................................................//
		TCalculator c;
		c.SetExpr("(2/0)");
		double a = c.Calc();
		cout << a << endl;

	/*
		TStack<int> a;
		TCalculator c;
		string str1 = "(10/(-0.1)+1+10^2*3)/5.55";
		string str2 = "-5+6";
		c.SetExpr(str1);
		string test = c.ToPostfix();
		cout << str1 << " = " << test << endl;
		double res = c.Calc();
		cout << endl << str1 << " = " << res << endl;
		c.SetExpr(str2);
		res = c.OldCalc();
		//cout << endl << str2 << " = " << res << endl;
	//.......................................................//*/
	system("pause");
	return 0;
}