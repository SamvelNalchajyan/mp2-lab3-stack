#pragma once
#include <string>
#include "Stack.h"

class TCalculator
{
private:
	std::string expr;
	TStack<char> st_char;
	TStack<double> st_double;
public:
	TCalculator(): st_char(100), st_double(100) {}
	void SetExpr(std::string s);
	std::string GetExpr();
	bool Check();
	int Prior(char c);
	std::string ToPostfix();
	double Calc();
};