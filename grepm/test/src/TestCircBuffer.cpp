#include <gtest/gtest.h>
#include <CircBuffer.h>

TEST(TestCircBuffer, Test1)
{
  CircBuffer buffer(1);

  ASSERT_EQ(0, buffer.size());

  buffer.add("one");
  ASSERT_EQ(1, buffer.size());
  ASSERT_EQ("one", buffer.get(0));

  buffer.add("two");
  ASSERT_EQ(1, buffer.size());
  ASSERT_EQ("two", buffer.get(0));
}

TEST(TestCircBuffer, Test2)
{
  CircBuffer buffer(3);

  ASSERT_EQ(0, buffer.size());

  buffer.add("one");
  ASSERT_EQ(1, buffer.size());
  ASSERT_EQ("one", buffer.get(0));

  buffer.add("two");
  ASSERT_EQ(2, buffer.size());
  ASSERT_EQ("two", buffer.get(1));

  buffer.add("three");
  ASSERT_EQ(3, buffer.size());
  ASSERT_EQ("three", buffer.get(2));

  buffer.add("four");
  ASSERT_EQ(3, buffer.size());
  ASSERT_EQ("four", buffer.get(2));
}