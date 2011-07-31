#include <gtest/gtest.h>
#include <ChainItem.h>
#include <Chain.h>

class MyChainItem : public ChainItem
{
public:
  MyChainItem* getNext() { return dynamic_cast<MyChainItem*>(next_); }
};

// ChainManager
class MyChain : public Chain<MyChainItem>
{
public:
  MyChain(MyChainItem* root = NULL)
    : Chain<MyChainItem>(root)
  {}
	std::size_t getItemCount()
  {
    return empty() ? 0 : GetItemCountRecursive(getRoot());
	}

private:
	static std::size_t GetItemCountRecursive(MyChainItem* item)
  {
		if (item->getNext())
			return GetItemCountRecursive(item->getNext()) + 1;
		else
			return 1;
	}
};

TEST(TestChain, testEmpty)
{
  MyChain chain;

  ASSERT_TRUE(chain.empty());
  ASSERT_FALSE(chain.getRoot());
}

TEST(TestChain, testCtor)
{
  MyChainItem chainItem;
  MyChain chain(&chainItem);

  ASSERT_FALSE(chain.empty());
  ASSERT_EQ(&chainItem, chain.getRoot());
}

TEST(TestChain, testAddElements)
{
	MyChain chain;
	ASSERT_EQ(std::size_t(0), chain.getItemCount());

	MyChainItem chainItem1;
	MyChainItem chainItem2;

	chain.add(&chainItem1);
	ASSERT_EQ(std::size_t(1), chain.getItemCount());

	chain.add(&chainItem2);
	ASSERT_EQ(std::size_t(2), chain.getItemCount());

	EXPECT_THROW(chain.add(&chainItem2), std::logic_error);
}

TEST(TestChain, testAvoidAddingSameItemTwice)
{
  MyChain chain;
	MyChainItem chainItem1;
  MyChainItem chainItem2;
	chain.add(&chainItem1);
  chain.add(&chainItem2);
	EXPECT_THROW(chain.add(&chainItem1), std::logic_error);
}

TEST(TestChain, testAddSameItem)
{
	MyChain chain;
	ASSERT_EQ(std::size_t(0), chain.getItemCount());

	MyChainItem chainItem1;

	chain.add(&chainItem1);
	ASSERT_EQ(std::size_t(1), chain.getItemCount());

	EXPECT_THROW(chain.add(&chainItem1), std::logic_error);
}
