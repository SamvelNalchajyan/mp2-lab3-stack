#include "gtest.h"
#include "../mp2-lab3-stack/Stack.h"

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(10));
}

TEST(TStack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(TStack<int> st(MAX_STACK_SIZE + 1));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, can_check_empty_stack)
{
	TStack<int> s1(10);
	bool a = s1.IsEmpty();
	EXPECT_EQ(a, true);
}

TEST(TStack, can_check_full_stack)
{
	TStack<int> s1(1);
	s1.Push(1);
	bool a = s1.IsFull();
	EXPECT_EQ(a, true);
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> s1(50);
	ASSERT_NO_THROW(TStack<int> s2(s1));
}

TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> s1(10);
	TStack<int> s2(s1);
	s1.Push(1);
	ASSERT_ANY_THROW(int a = s2.Pop());
}

TEST(TStack, can_push_to_stack)
{
	TStack<int> s1(10);
	ASSERT_NO_THROW(s1.Push(1));
}

TEST(TStack, can_pop_of_stack)
{
	TStack<int> s1(10);
	s1.Push(1);
	int a = 0;
	ASSERT_NO_THROW(a = s1.Pop());
	EXPECT_EQ(a, 1);
}

TEST(TStack, can_not_push_to_full_stack)
{
	TStack<int> s1(1);
	s1.Push(1);
	ASSERT_ANY_THROW(s1.Push(10));
}

TEST(TStack, can_not_pop_of_empty_stack)
{
	TStack<int> s1(10);
	ASSERT_ANY_THROW(int a = s1.Pop());
}

TEST(TStack, can_assign_vector_to_itself)
{
	TStack<int> s1(10);
	ASSERT_NO_THROW(s1 = s1);
}

TEST(TStack, can_assign_stacks_of_equal_size)
{
	TStack<int> s1(10), s2(10);
	s2.Push(1);
	ASSERT_NO_THROW(s1 = s2);
	int a = s1.Pop();
	EXPECT_EQ(a, 1);
}

TEST(TStack, can_assign_stacks_of_different_size)
{
	TStack<int> s1(10), s2(20);
	s2.Push(1);
	ASSERT_NO_THROW(s1 = s2);
	int a = s1.Pop();
	EXPECT_EQ(a, 1);
}

TEST(TStack, assignment_operator_can_change_stack_size)
{
	TStack<int> s1(1), s2(2);
	s2 = s1;
	s2.Push(1);
	ASSERT_ANY_THROW(s2.Push(2));
}

TEST(TStack, assignment_operator_works_correctly)
{
	TStack<int> s1(10), s2(10);
	for (int i = 0; i < 10; i++)
	{
		s1.Push(i);
	}
	s2 = s1;
	for (int i = 0; i > 0; i--)
	{
		int a = s2.Pop();
		EXPECT_EQ(a, i);
	}
}