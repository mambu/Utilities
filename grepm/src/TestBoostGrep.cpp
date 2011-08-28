#include <gtest/gtest.h>
#include <BoostGrep.h>

TEST(TestBoostGrep, TestGrep1)
{
  BoostGrep grep("hi1");
  ASSERT_TRUE(grep.process("hi1\n"));
  ASSERT_FALSE(grep.process("hi2\n"));
}

TEST(TestBoostGrep, TestGrep2)
{
  BoostGrep grep("hi");
  ASSERT_TRUE(grep.process("hi1\n"));
  ASSERT_TRUE(grep.process("hi2\n"));
  ASSERT_TRUE(grep.process("ahi\n"));
  ASSERT_TRUE(grep.process("1hi\n"));
}

TEST(TestBoostGrep, TestGrep3)
{
  BoostGrep grep("h.i");
  ASSERT_FALSE(grep.process("hi\n"));
  ASSERT_TRUE(grep.process("h1i\n"));
  ASSERT_TRUE(grep.process("hAi\n"));
  ASSERT_TRUE(grep.process("h?i\n"));
}

TEST(TestBoostGrep, TestGrep4)
{
  BoostGrep grep("h.*i");
  ASSERT_TRUE(grep.process("hi\n"));
  ASSERT_TRUE(grep.process("h1i\n"));
  ASSERT_TRUE(grep.process("h1Ai\n"));
  ASSERT_TRUE(grep.process("h1A?i\n"));
}

TEST(TestBoostGrep, TestGrep5)
{
  BoostGrep grep("h\\\\a\\.");
  ASSERT_TRUE(grep.process("_h\\a._\n"));
}

TEST(TestBoostGrep, TestGrep6)
{
  BoostGrep grep("^h");
  ASSERT_TRUE(grep.process("h_\n"));
  ASSERT_FALSE(grep.process("_h\n"));
}
