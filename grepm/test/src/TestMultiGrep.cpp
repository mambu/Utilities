#include <gtest/gtest.h>
#include <MultiGrep.h>

class TestFilter : public Filter
{
public:
  TestFilter(std::size_t count)
    : count_(count)
    , counter_(0)
  {}

  bool process(const std::string& line)
  {
    counter_++;
    return counter_ == count_;
  }

  void reset()
  {
    counter_ = 0;
  }

private:
  std::size_t count_;
  std::size_t counter_;
};

TEST(TestMultiGrep, TestGrep1)
{
  std::string line;
  TestFilter testFilter(1);
  MultiGrep grep(testFilter, 1);
  grep.process("hi1\n"); // x - M
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi1\n", line);
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi2\n"); // x
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi2\n", line);
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi3\n");
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi4\n");
  ASSERT_FALSE(grep.hasNext());
}

TEST(TestMultiGrep, TestGrep2)
{
  std::string line;
  TestFilter testFilter(2);
  MultiGrep grep(testFilter, 1);
  grep.process("hi1\n"); // x
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi2\n"); // x - M
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi1\n", line);
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi2\n", line);
  grep.process("hi3\n"); // x
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi3\n", line);
  grep.process("hi4\n");
  ASSERT_FALSE(grep.hasNext());
}

TEST(TestMultiGrep, TestGrep3)
{
  std::string line;
  TestFilter testFilter(3);
  MultiGrep grep(testFilter, 1);
  grep.process("hi1\n");
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi2\n"); // x
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi3\n"); // x - M
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi2\n", line);
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi3\n", line);
  grep.process("hi4\n"); // x
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi4\n", line);
  ASSERT_FALSE(grep.hasNext());
}

TEST(TestMultiGrep, TestGrep4)
{
  std::string line;
  TestFilter testFilter(4);
  MultiGrep grep(testFilter, 1);
  grep.process("hi1\n");
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi2\n");
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi3\n"); // x
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi4\n"); // x - M
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
  TestFilter testFilter(1);
  MultiGrep grep(testFilter, 1);
  grep.process("hi1\n");
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi1\n", line);
  grep.process("hi2\n");
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi2\n", line);
  grep.process("hi3\n");
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi4\n");
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi5\n");
  ASSERT_FALSE(grep.hasNext());
  testFilter.reset();
  grep.process("hi6\n");
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
  TestFilter testFilter(1);
  MultiGrep grep(testFilter, 2);
  grep.process("hi1\n"); // x - M
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi1\n", line);
  grep.process("hi2\n"); // x
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi2\n", line);
  grep.process("hi3\n"); // x
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi3\n", line);
  grep.process("hi4\n");
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi5\n"); // x
  ASSERT_FALSE(grep.hasNext());
  grep.process("hi6\n"); // x
  ASSERT_FALSE(grep.hasNext());
  testFilter.reset();
  grep.process("hi7\n"); // x - M
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
  TestFilter testFilter(1);
  MultiGrep grep(testFilter, 0); // no multiple lines, no buffering
  grep.process("hi1\n"); // x - M
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi1\n", line);
  grep.process("hi2\n");
  ASSERT_FALSE(grep.hasNext());
  testFilter.reset();
  grep.process("hi3\n"); // x - M
  ASSERT_TRUE(grep.hasNext());
  grep.getNext(line);
  ASSERT_EQ("hi3\n", line);
  ASSERT_FALSE(grep.hasNext());
}
