#include "stack.hpp"
#include "gtest/gtest.h"

using namespace DSAlgoTest::list;

TEST(stackTests, emptyStack) {
	stack st;
	ASSERT_EQ(st.size(), 0);
}

TEST(stackTests, pushTopTest) {
	stack st;
	int val = 10;
	st.push(10);

	ASSERT_EQ(st.size(), 1);
	EXPECT_EQ(val, st.top());
}

TEST(stackTests, pushPopTest) {
	stack st;
	int val = 10;
	st.push(10);

	st.pop();

	ASSERT_EQ(st.size(), 0);
}

TEST(stackTests, TopEmptyStackTest) {
	stack st;

	ASSERT_THROW(st.top(), std::out_of_range);
}

TEST(stackTests, MultiplepushPopTest) {
	stack st;
	int len = 10;
	for (auto i = 0; i < len; ++i) {
		st.push(i);
	}

	for (auto i = 0; i < len; ++i) {
		EXPECT_EQ(st.top(), len - i - 1);
		st.pop();
	}

	ASSERT_EQ(st.size(), 0);
}
