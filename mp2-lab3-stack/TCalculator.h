#pragma once
#include <string>
//#include "Stack.h"
#include "TStackList.h"

class TCalculator
{
private:
	std::string expr;
	TStack<char> st_char;
	TStack<double> st_double;
	int Prior(char c);
public:
	TCalculator(): st_char(100), st_double(100) {}
	void SetExpr(std::string s);
	std::string GetExpr();
	bool Check();
	std::string ToPostfix();
	double OldCalc();
	double Calc();
};