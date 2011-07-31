#include <gtest/gtest.h>
#include <LineNumber.h>

TEST(TestLineNumber, Test1)
{
  LineNumber lineNumber;

  std::string line;
  lineNumber.process(line);

  ASSERT_EQ("1:", line);
}

TEST(TestLineNumber, Test2)
{
  LineNumber lineNumber;

  std::string line;
  lineNumber.process(line);
  line = "";
  lineNumber.process(line);

  ASSERT_EQ("2:", line);
}

TEST(TestLineNumber, Test3)
{
  LineNumber lineNumber;

  std::string line = "first line";
  lineNumber.process(line);

  ASSERT_EQ("1:first line", line);
}

TEST(TestLineNumber, Test4)
{
  LineNumber lineNumber;

  std::string line = "  first\tline";
  lineNumber.process(line);

  ASSERT_EQ("1:  first\tline", line);
}
