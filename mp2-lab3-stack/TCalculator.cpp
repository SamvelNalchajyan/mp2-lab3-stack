#include "TCalculator.h"

void TCalculator::SetExpr(std::string s)
{
	expr = s;
}

std::string TCalculator::GetExpr()
{
	return expr;
}

bool TCalculator::Check()
{
	st_char.Clear();
	for (int i = 0; i < expr.size(); i++)
	{
		if (expr[i] == '(')
		{
			st_char.Push(expr[i]);
		}
		if (expr[i] == ')')
		{
			if (st_char.IsEmpty())
			{
				return false;
			}
			else
			{
				st_char.Pop();
			}
		}
	}
	return st_char.IsEmpty();
}

int TCalculator::Prior(char c)
{
	if (c == '(')
	{
		return 0;
	}
	if (c == '+' || c == '-')
	{
		return 1;
	}
	if (c == '*' || c == '/')
	{
		return 2;
	}
	if (c == '^')
	{
		return 3;
	}
}

std::string TCalculator::ToPostfix()
{
	std::string postfix;
	return postfix;
}

double TCalculator::Calc()
{
	double res = 0;
	return res;
}