#include "list.hpp"
#include "gtest/gtest.h"

class listProblemsTests : public testing::Test {
public:
	DSAlgo::list<> _list;
};

TEST_F(listProblemsTests, mth_to_last_element) {
	int len = 10;
	for (auto i = 1; i <= len; ++i) {
		_list.insertAtEnd(i);
	}

	EXPECT_EQ(10, _list.mth_to_last_element(0));
	EXPECT_EQ(8, _list.mth_to_last_element(2));
	EXPECT_EQ(2, _list.mth_to_last_element(8));
	EXPECT_EQ(1, _list.mth_to_last_element(len));
	ASSERT_THROW(_list.mth_to_last_element(-1), std::invalid_argument);
	ASSERT_THROW(_list.mth_to_last_element(20), std::invalid_argument);
}

TEST_F(listProblemsTests, mth_to_last_element_2) {
	ASSERT_THROW(_list.mth_to_last_element_2(0), std::out_of_range);
	int len = 10;
	for (auto i = 1; i <= len; ++i) {
		_list.insertAtEnd(i);
	}

	EXPECT_EQ(10, _list.mth_to_last_element_2(0));
	EXPECT_EQ(9, _list.mth_to_last_element_2(2));
	EXPECT_EQ(3, _list.mth_to_last_element_2(8));
	EXPECT_EQ(1, _list.mth_to_last_element_2(len));
	ASSERT_THROW(_list.mth_to_last_element_2(-1), std::invalid_argument);
	ASSERT_THROW(_list.mth_to_last_element_2(20), std::out_of_range);
}

TEST_F(listProblemsTests, isCyclic) {
	EXPECT_FALSE(_list.isCyclic());
	int len = 10;
	for (auto i = 1; i <= len; ++i) {
		_list.insertAtEnd(i);
	}

	EXPECT_FALSE(_list.isCyclic());

	auto* last = _list.findAtIndex(10);
	auto* middle = _list.findAtIndex(5);
	last->setNext(middle);
	EXPECT_TRUE(_list.isCyclic());
	last->setNext(nullptr);
}
