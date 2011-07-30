#include <gtest/gtest.h>
#include <CircBuffer.h>

TEST(TestCircBuffer, Test1)
{
  CircBuffer buffer(1);

  ASSERT_EQ(0, buffer.size());

  buffer.add("one");
  ASSERT_EQ(1, buffer.size());
  ASSERT_EQ("one", buffer.get(0));
  ASSERT_EQ("one", buffer.get());

  buffer.add("two");
  ASSERT_EQ(1, buffer.size());
  ASSERT_EQ("two", buffer.get(0));
  ASSERT_EQ("two", buffer.get());
}

TEST(TestCircBuffer, Test2)
{
  CircBuffer buffer(3);

  ASSERT_EQ(0, buffer.size());

  buffer.add("one");
  ASSERT_EQ(1, buffer.size());
  ASSERT_EQ("one", buffer.get(0));
  ASSERT_EQ("one", buffer.get());

  buffer.add("two");
  ASSERT_EQ(2, buffer.size());
  ASSERT_EQ("two", buffer.get(1));
  ASSERT_EQ("one", buffer.get());

  buffer.add("three");
  ASSERT_EQ(3, buffer.size());
  ASSERT_EQ("three", buffer.get(2));
  ASSERT_EQ("one", buffer.get());

  buffer.add("four");
  ASSERT_EQ(3, buffer.size());
  ASSERT_EQ("four", buffer.get(2));
  ASSERT_EQ("two", buffer.get());
}

TEST(TestCircBuffer, Test3)
{
  CircBuffer buffer(3);

  buffer.add("one");
  ASSERT_EQ(1, buffer.size());
  ASSERT_EQ("one", buffer.get(0));

  buffer.shift();
  ASSERT_EQ(0, buffer.size());
}

TEST(TestCircBuffer, TestEmpty)
{
  CircBuffer buffer(3);

  ASSERT_TRUE(buffer.empty());
  ASSERT_EQ(0, buffer.size());

  buffer.add("one");
  ASSERT_EQ(1, buffer.size());
  ASSERT_FALSE(buffer.empty());

  buffer.shift();
  ASSERT_EQ(0, buffer.size());
  ASSERT_TRUE(buffer.empty());
}
