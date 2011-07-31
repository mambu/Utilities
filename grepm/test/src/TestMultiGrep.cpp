#include <gtest/gtest.h>
#include <MultiGrep.h>

TEST(TestMultiGrep, TestGrep1)
{
  std::string line;
  MultiGrep grep(1);
  grep.process("hi1\n", true); // x - M
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi1\n", line);
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi2\n", false); // x
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi2\n", line);
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi3\n", false);
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi4\n", false);
  ASSERT_FALSE(grep.hasNext());
}

TEST(TestMultiGrep, TestGrep2)
{
  std::string line;
  MultiGrep grep(1);
  grep.process("hi1\n", false); // x
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi2\n", true); // x - M
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi1\n", line);
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi2\n", line);
  grep.process("hi3\n", false); // x
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi3\n", line);
  grep.process("hi4\n", false);
  ASSERT_FALSE(grep.hasNext());
}

TEST(TestMultiGrep, TestGrep3)
{
  std::string line;
  MultiGrep grep(1);
  grep.process("hi1\n", false);
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi2\n", false); // x
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi3\n", true); // x - M
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi2\n", line);
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi3\n", line);
  grep.process("hi4\n", false); // x
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi4\n", line);
  ASSERT_FALSE(grep.hasNext());
}

TEST(TestMultiGrep, TestGrep4)
{
  std::string line;
  MultiGrep grep(1);
  grep.process("hi1\n", false);
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi2\n", false);
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi3\n", false); // x
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi4\n", true); // x - M
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi3\n", line);
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi4\n", line);
  ASSERT_FALSE(grep.hasNext());
}

TEST(TestMultiGrep, TestGrep5)
{
  std::string line;
  MultiGrep grep(1);
  grep.process("hi1\n", true);
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi1\n", line);
  grep.process("hi2\n", false);
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi2\n", line);
  grep.process("hi3\n", false);
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi4\n", false);
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi5\n", false);
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi6\n", true);
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi5\n", line);
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi6\n", line);
  ASSERT_FALSE(grep.hasNext());
}

TEST(TestMultiGrep, TestGrep6)
{
  std::string line;
  MultiGrep grep(2);
  grep.process("hi1\n", true); // x - M
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi1\n", line);
  grep.process("hi2\n", false); // x
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi2\n", line);
  grep.process("hi3\n", false); // x
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi3\n", line);
  grep.process("hi4\n", false);
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi5\n", false); // x
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi6\n", false); // x
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi7\n", true); // x - M
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi5\n", line);
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi6\n", line);
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi7\n", line);
  ASSERT_FALSE(grep.hasNext());
}

TEST(TestMultiGrep, TestGrep7)
{
  std::string line;
  MultiGrep grep(0); // no multiple lines, no buffering
  grep.process("hi1\n", true); // x - M
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi1\n", line);
  grep.process("hi2\n", false);
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi3\n", true); // x - M
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi3\n", line);
  ASSERT_FALSE(grep.hasNext());
}
