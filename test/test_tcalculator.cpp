#include "gtest.h"
#include "../mp2-lab3-stack/TCalculator.h"

TEST(TCalculator, can_create_calculator)
{
	ASSERT_NO_THROW(TCalculator c);
}
/*
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
*/