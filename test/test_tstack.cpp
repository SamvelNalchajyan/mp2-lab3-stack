#include "gtest.h"
#include "../mp2-lab3-stack/Stack.h"

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(10));
}
