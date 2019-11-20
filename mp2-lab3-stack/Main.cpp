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
	string str = "5+(5-4)/2";
	c.SetExpr(str);
	string test = c.ToPostfix();
	cout << test << endl;
	//.......................................................//
	system("pause");
	return 0;
}