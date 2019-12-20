#include "gtest.h"
#include "../mp2-lab3-stack/TCalculator.h"

TEST(TCalculator, can_create_calculator)
{
	ASSERT_NO_THROW(TCalculator c);
}

TEST(TCalculator, can_set_expression)
{
	TCalculator c;
	std::string expr = "8+3*8";
	ASSERT_NO_THROW(c.SetExpr(expr));
}

TEST(TCalculator, can_get_expression)
{
	TCalculator c;
	std::string expr = "8+3*8";
	c.SetExpr(expr);
	ASSERT_NO_THROW(std::string tmp = c.GetExpr());
	EXPECT_EQ(c.GetExpr(), expr);
}

TEST(TCalculator, check_function_works_correctly)
{
	TCalculator c;
	c.SetExpr("((2)+(2))");
	ASSERT_NO_THROW(c.Check());
	EXPECT_EQ(c.Check(), 1);
	c.SetExpr("(2)+(2))");
	ASSERT_NO_THROW(c.Check());
	EXPECT_EQ(c.Check(), 0);
}

TEST(TCalculator, un_minus_works_correctly)
{
	TCalculator c;
	c.SetExpr("-5");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), -5);
	c.SetExpr("-3.14");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), -3.14);
	c.SetExpr("-0");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 0);
	c.SetExpr("-(1/2)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), -0.5);
}

TEST(TCalculator, cacl_function_works_correctly_with_plus_for_int)
{
	TCalculator c;
	c.SetExpr("5+7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 + 7);
	c.SetExpr("0+7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 7);
}

TEST(TCalculator, cacl_function_works_correctly_with_plus_for_double)
{
	TCalculator c;
	c.SetExpr("1/2+1/2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1);
	c.SetExpr("0+1/2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 0.5);
	c.SetExpr("1/2+1/4");
	ASSERT_NO_THROW(c.Calc());
	double sum = (1.0 / 2) + (1.0 / 4);
	EXPECT_EQ(c.Calc(), sum);
}

TEST(TCalculator, cacl_function_works_correctly_with_minus_for_int)
{
	TCalculator c;
	c.SetExpr("5-7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 - 7);
	c.SetExpr("7-2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 7 - 2);
	c.SetExpr("0-7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), -7);
}

TEST(TCalculator, cacl_function_works_correctly_with_minus_for_double)
{
	TCalculator c;
	c.SetExpr("1/2-1/2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 0);
	c.SetExpr("0-1/2");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), -0.5);
	c.SetExpr("1/2-1/4");
	ASSERT_NO_THROW(c.Calc());
	double sum = (1.0 / 2) - (1.0 / 4);
	EXPECT_EQ(c.Calc(), sum);
}

TEST(TCalculator, cacl_function_works_correctly_with_mult_for_int)
{
	TCalculator c;
	c.SetExpr("5*7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * 7);
	c.SetExpr("0*7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 0 * 7);
	c.SetExpr("5*(-7)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 * (-7));
}

TEST(TCalculator, cacl_function_works_correctly_with_mult_for_double)
{
	TCalculator c;
	c.SetExpr("1/2*1/2");
	ASSERT_NO_THROW(c.Calc());
	double sum = (1.0 / 2) * (1.0 / 2);
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("0*1/2");
	ASSERT_NO_THROW(c.Calc());
	sum = 0 * (1.0 / 2);
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("1/2*(-1/4)");
	ASSERT_NO_THROW(c.Calc());
	sum = ((1.0 / 2) * (-(1.0 / 4)));
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("1*1/2");
	ASSERT_NO_THROW(c.Calc());
	sum = 1 * (1.0 / 2);
	EXPECT_EQ(c.Calc(), sum);
}

TEST(TCalculator, cacl_function_works_correctly_with_div_for_int)
{
	TCalculator c;
	c.SetExpr("5/7");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5.0 / 7);
	c.SetExpr("0/7");
	ASSERT_NO_THROW(c.Calc()); 
	EXPECT_EQ(c.Calc(), 0 / 7);
	c.SetExpr("5/(-7)");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5.0 / (-7));
	c.SetExpr("5/0");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), INFINITY);

}

TEST(TCalculator, cacl_function_works_correctly_with_diff_op_for_double)
{
	TCalculator c;
	c.SetExpr("(1.1/2)/(1/2.1)");
	ASSERT_NO_THROW(c.Calc());
	double sum = (1.1 / 2) / (1.0 / 2.1);
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("0/(1/2.1)");
	ASSERT_NO_THROW(c.Calc());
	sum = (0 / (1 / (2.1)));
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("(1/2.3)/(-1/4.4)");
	ASSERT_NO_THROW(c.Calc());
	sum = ((1.0 / 2.3) / (-(1.0 / 4.4)));
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("1/(1/2.1)");
	ASSERT_NO_THROW(c.Calc());
	sum = 1 / (1.0 / 2.1);
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("(1/5.1)/0");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), INFINITY);
}

TEST(TCalculator, cacl_function_works_correctly_with_vozv_v_step_for_int)
{
	TCalculator c;
	c.SetExpr("5^0");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 1);
	c.SetExpr("0^5");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 0);
	c.SetExpr("5^2");
	ASSERT_NO_THROW(c.Calc());
	double sum = pow(5, 2);
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("5^(-2)");
	ASSERT_NO_THROW(c.Calc());
	sum = pow(5, -2);
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("(-2)^5");
	ASSERT_NO_THROW(c.Calc());
	sum = pow((-2), 5);
	EXPECT_EQ(c.Calc(), sum);
	c.SetExpr("(-2)^4");
	ASSERT_NO_THROW(c.Calc());
	sum = pow((-2), 4);
	EXPECT_EQ(c.Calc(), sum);
}

TEST(TCalculator, cacl_function_works_correctly_for_diff_alg_op) {
	TCalculator c;
	double res;
	c.SetExpr("(5+5)*5");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 50);
	c.SetExpr("5+5*5");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 30);
	c.SetExpr("(5+5)/5");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 2);
	c.SetExpr("5+5/5");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 6);
	c.SetExpr("5+5^2/5");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), 5 + pow(5, 2) / 5);
	c.SetExpr("5/5+(2^5-1+8*7)-1");
	ASSERT_NO_THROW(c.Calc());
	EXPECT_EQ(c.Calc(), ((5 / 5) + ((pow(2, 5)) - 1 + 8 * 7) - 1));
}
