#include <gtest/gtest.h>
#include <MultiGrep.h>

class TestStringProcessor : public StringProcessor
{
public:
  TestStringProcessor(std::size_t count)
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
  TestStringProcessor testProcessor(1);
  std::ostringstream os;
  MultiGrep grep(testProcessor, os, 1);
  grep.process("hi1\n"); // x - M
  grep.process("hi2\n"); // x
  grep.process("hi3\n"); // x
  grep.process("hi4\n");

  ASSERT_EQ(std::string("hi1\nhi2\n"), os.str());
}

TEST(TestMultiGrep, TestGrep2)
{
  TestStringProcessor testProcessor(2);
  std::ostringstream os;
  MultiGrep grep(testProcessor, os, 1);
  grep.process("hi1\n"); // x
  grep.process("hi2\n"); // x - M
  grep.process("hi3\n"); // x
  grep.process("hi4\n");

  ASSERT_EQ(std::string("hi1\nhi2\nhi3\n"), os.str());
}

TEST(TestMultiGrep, TestGrep3)
{
  TestStringProcessor testProcessor(3);
  std::ostringstream os;
  MultiGrep grep(testProcessor, os, 1);
  grep.process("hi1\n");
  grep.process("hi2\n"); // x
  grep.process("hi3\n"); // x - M
  grep.process("hi4\n"); // x

  ASSERT_EQ(std::string("hi2\nhi3\nhi4\n"), os.str());
}

TEST(TestMultiGrep, TestGrep4)
{
  TestStringProcessor testProcessor(4);
  std::ostringstream os;
  MultiGrep grep(testProcessor, os, 1);
  grep.process("hi1\n");
  grep.process("hi2\n"); // x
  grep.process("hi3\n"); // x
  grep.process("hi4\n"); // x - M

  ASSERT_EQ(std::string("hi3\nhi4\n"), os.str());
}

TEST(TestMultiGrep, TestGrep5)
{
  TestStringProcessor testProcessor(1);
  std::ostringstream os;
  MultiGrep grep(testProcessor, os, 1);
  grep.process("hi1\n");
  grep.process("hi2\n");
  grep.process("hi3\n");
  grep.process("hi4\n");
  grep.process("hi5\n");
  testProcessor.reset();
  grep.process("hi6\n");

  ASSERT_EQ(std::string("hi1\nhi2\nhi5\nhi6\n"), os.str());
}

TEST(TestMultiGrep, TestGrep6)
{
  TestStringProcessor testProcessor(1);
  std::ostringstream os;
  MultiGrep grep(testProcessor, os, 2);
  grep.process("hi1\n"); // x - M
  grep.process("hi2\n"); // x
  grep.process("hi3\n"); // x
  grep.process("hi4\n");
  grep.process("hi5\n"); // x
  grep.process("hi6\n"); // x
  testProcessor.reset();
  grep.process("hi7\n"); // x - M

  ASSERT_EQ(std::string("hi1\nhi2\nhi3\nhi5\nhi6\nhi7\n"), os.str());
}

TEST(TestMultiGrep, TestGrep7)
{
  TestStringProcessor testProcessor(1);
  std::ostringstream os;
  MultiGrep grep(testProcessor, os, 0); // no multiple lines
  grep.process("hi1\n"); // x - M
  grep.process("hi2\n");
  testProcessor.reset();
  grep.process("hi3\n"); // x - M

  ASSERT_EQ(std::string("hi1\nhi3\n"), os.str());
}
