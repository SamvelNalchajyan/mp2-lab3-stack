#include <cmath>
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
	std::string postfix = "";
	std::string str = "(";
	str += expr;
	str += ")";
	st_char.Clear();
	for (int i = 0; i < str.size() - 1; i++)
	{
		if (str[i] == '(')
		{
			if (str[i + 1] == '-' || str[i + 1] == '+')
			{
				postfix += '0';
			}
			st_char.Push(str[i]);
		}
		if (str[i] >= '0' && str[i] <= '9' || str[i] == '.')
		{
			postfix += str[i];
		}
		if (str[i] == ')')
		{
			char tmp = st_char.Pop();
			while (tmp != '(')
			{
				postfix += tmp;
				tmp = st_char.Pop();
			}
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
		{
			postfix += " ";
			char tmp = st_char.Pop();
			while (Prior(str[i]) <= Prior(tmp))
			{
				postfix += tmp;
				tmp = st_char.Pop();
			}
			st_char.Push(tmp);
			st_char.Push(str[i]);
		}
	}
	char tmp = st_char.Pop();
	while (tmp != '(')
	{
		postfix += tmp;
		tmp = st_char.Pop();
	}
	return postfix;
}

double TCalculator::Calc()
{
	double res;
	st_double.Clear();
	std::string postfix = ToPostfix();
	char *tmp;
	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			double d = strtod(&postfix[i], &tmp);
			int j = tmp - &postfix[i];
			i += j - 1;
			st_double.Push(d);
		}
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
		{
			double op1, op2;
			op2 = st_double.Pop();
			op1 = st_double.Pop();
			if (postfix[i] == '+')
			{
				res = op1 + op2;
			}
			if (postfix[i] == '-')
			{
				res = op1 - op2;
			}
			if (postfix[i] == '*')
			{
				res = op1 * op2;
			}
			if (postfix[i] == '/')
			{
				if (op2 != 0)
				{
					res = op1 / op2;
				}
				else
				{
					throw -1;
				}
			}
			if (postfix[i] == '^')
			{
				res = pow(op1, op2);
			}
			st_double.Push(res);
		}
	}
	res = st_double.Pop();
	return res;
}