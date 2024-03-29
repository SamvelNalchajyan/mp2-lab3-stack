#define _USE_MATH_DEFINES
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
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			postfix += str[i];
		}
		if (str[i] >= 'a' && str[i] <= 'z')
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

double TCalculator::OldCalc()
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
				/*
				if (op2 != 0)
				{
					res = op1 / op2;
				}
				else
				{
					throw -1;
				}
				*/
				res = op1 / op2;
				st_double.Push(res);
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

double TCalculator::Calc()
{
	double res = 0;
	std::string str = "(";
	str += expr;
	str += ")";
	st_char.Clear();
	st_double.Clear();
	for (int i = 0; i < str.size() - 1; i++)
	{
		if (str[i] == '(')
		{
			if (str[i + 1] == '-' || str[i + 1] == '+')
			{
				st_double.Push(0);
			}
			st_char.Push(str[i]);
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			char *tmp;
			double d = strtod(&str[i], &tmp);
			int j = tmp - &str[i];
			i += j - 1;
			st_double.Push(d);
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
		{
			char tmp = st_char.Pop();
			while (Prior(str[i]) <= Prior(tmp))
			{
				double op1, op2;
				op2 = st_double.Pop();
				op1 = st_double.Pop();
				if (tmp == '+')
				{
					res = op1 + op2;
					st_double.Push(res);
				}
				if (tmp == '-')
				{
					res = op1 - op2;
					st_double.Push(res);
				}
				if (tmp == '*')
				{
					res = op1 * op2;
					st_double.Push(res);
				}
				if (tmp == '/')
				{
					/*
					if (op2 != 0)
					{
						res = op1 / op2;
						st_double.Push(res);
					}
					else
					{
						throw - 1;
					}
					*/
					res = op1 / op2;
					st_double.Push(res);
				}
				if (tmp == '^')
				{
					res = pow(op1, op2);
					st_double.Push(res);
				}
				tmp = st_char.Pop();
			}
			st_char.Push(tmp);
			st_char.Push(str[i]);
		}
		if (str[i] == ')')
		{
			char tmp = st_char.Pop();
			while (tmp != '(')
			{
				if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/' || tmp == '^')
				{
					double op1, op2;
					op2 = st_double.Pop();
					op1 = st_double.Pop();
					if (tmp == '+')
					{
						res = op1 + op2;
						st_double.Push(res);
					}
					if (tmp == '-')
					{
						res = op1 - op2;
						st_double.Push(res);
					}
					if (tmp == '*')
					{
						res = op1 * op2;
						st_double.Push(res);
					}
					if (tmp == '/')
					{
						/*
						if (op2 != 0)
						{
							res = op1 / op2;
							st_double.Push(res);
						}
						else
						{
							throw 1;
						}
						*/
						res = op1 / op2;
						st_double.Push(res);
					}
					if (tmp == '^')
					{
						res = pow(op1, op2);
						st_double.Push(res);
					}
				}
				tmp = st_char.Pop();
			}
			/*
			if (tmp == 's')
			{
				res = st_double.Pop();
				res = sin(res);
				st_double.Push(res);
			}
			*/
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str[i] == 'P' && str[i + 1] == 'i')
			{
				st_double.Push(M_PI);
				i++;
			}
			if (str[i] == 'E')
			{
				st_double.Push(M_E);
			}
		}
		/*
		if (str[i] >= 'a' && str[i] <= 'z' && i <= str.size() - 5)
		{
			// sin
			if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'n')
			{
				i += 3;
				if (str[i + 1] == '-' || str[i + 1] == '+')
				{
					st_double.Push(0);
				}
				st_char.Push('s');
			}
			// cos
			if (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 's')
			{
				i += 3;
				if (str[i + 1] == '-' || str[i + 1] == '+')
				{
					st_double.Push(0);
				}
				st_char.Push('c');
			}
			// tg
			if (str[i] == 't' && str[i + 1] == 'g')
			{
				i += 2;
				if (str[i + 1] == '-' || str[i + 1] == '+')
				{
					st_double.Push(0);
				}
				st_char.Push('t');
			}
			// ctg
			if (str[i] == 'c' && str[i + 1] == 't' && str[i + 2] == 'g')
			{
				i += 3;
				if (str[i + 1] == '-' || str[i + 1] == '+')
				{
					st_double.Push(0);
				}
				st_char.Push('v');
			}
			// sh
			if (str[i] == 's' && str[i + 1] == 'h')
			{
				i += 2;
				if (str[i + 1] == '-' || str[i + 1] == '+')
				{
					st_double.Push(0);
				}
				st_char.Push('h');
			}
			// ch
			if (str[i] == 'c' && str[i + 1] == 'h')
			{
				i += 2;
				if (str[i + 1] == '-' || str[i + 1] == '+')
				{
					st_double.Push(0);
				}
				st_char.Push('g');
			}
			// th
			if (str[i] == 't' && str[i + 1] == 'h')
			{
				i += 2;
				if (str[i + 1] == '-' || str[i + 1] == '+')
				{
					st_double.Push(0);
				}
				st_char.Push('j');
			}
			// cth
			if (str[i] == 'c' && str[i + 1] == 't' && str[i + 2] == 'h')
			{
				i += 3;
				if (str[i + 1] == '-' || str[i + 1] == '+')
				{
					st_double.Push(0);
				}
				st_char.Push('k');
			}
		}
		*/
	}
	char tmp = st_char.Pop();
	while (tmp != '(')
	{
		if (tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/' || tmp == '^')
		{
			double op1, op2;
			op2 = st_double.Pop();
			op1 = st_double.Pop();
			if (tmp == '+')
			{
				res = op1 + op2;
				st_double.Push(res);
			}
			if (tmp == '-')
			{
				res = op1 - op2;
				st_double.Push(res);
			}
			if (tmp == '*')
			{
				res = op1 * op2;
				st_double.Push(res);
			}
			if (tmp == '/')
			{
				/*
				if (op2 != 0)
				{
					res = op1 / op2;
					st_double.Push(res);
				}
				else
				{
					throw - 1;
				}
				*/
				res = op1 / op2;
				st_double.Push(res);
			}
			if (tmp == '^')
			{
				res = pow(op1, op2);
				st_double.Push(res);
			}
		}
		tmp = st_char.Pop();
	}
	res = st_double.Pop();
	return res;
}