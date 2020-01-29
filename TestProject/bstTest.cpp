#include "bst.hpp"
#include "gtest/gtest.h"

class bstTests : public testing::Test {
public:
	virtual void SetUp() override {
		_bst.insert(3);
		_bst.insert(1);
		_bst.insert(4);
		_bst.insert(6);
		_bst.insert(8);
		_bst.insert(2);
		_bst.insert(9);
		_bst.insert(0);
		//      3
		//    1   4
		//   0 2    6
		//            8
		//              9
	}
	DSAlgo::bst<> _bst;
};

TEST_F(bstTests, insertTest) {
	ASSERT_EQ(5, _bst.getHeight());
}

TEST_F(bstTests, inorder) {
	std::vector<int> out;
	_bst.inorder(out);
	ASSERT_EQ(8, out.size());
	EXPECT_EQ(0, out[0]);
	EXPECT_EQ(1, out[1]);
	EXPECT_EQ(2, out[2]);
	EXPECT_EQ(3, out[3]);
	EXPECT_EQ(4, out[4]);
	EXPECT_EQ(6, out[5]);
	EXPECT_EQ(8, out[6]);
	EXPECT_EQ(9, out[7]);
}

TEST_F(bstTests, preorder) {
	std::vector<int> out;
	_bst.preorder(out);
	ASSERT_EQ(8, out.size());
	EXPECT_EQ(3, out[0]);
	EXPECT_EQ(1, out[1]);
	EXPECT_EQ(0, out[2]);
	EXPECT_EQ(2, out[3]);
	EXPECT_EQ(4, out[4]);
	EXPECT_EQ(6, out[5]);
	EXPECT_EQ(8, out[6]);
	EXPECT_EQ(9, out[7]);
}

TEST_F(bstTests, postorder) {
	std::vector<int> out;
	_bst.postorder(out);
	ASSERT_EQ(8, out.size());
	EXPECT_EQ(0, out[0]);
	EXPECT_EQ(2, out[1]);
	EXPECT_EQ(1, out[2]);
	EXPECT_EQ(9, out[3]);
	EXPECT_EQ(8, out[4]);
	EXPECT_EQ(6, out[5]);
	EXPECT_EQ(4, out[6]);
	EXPECT_EQ(3, out[7]);
}

TEST_F(bstTests, getMax) {
	ASSERT_EQ(9, _bst.getMax());
}

TEST_F(bstTests, getMin) {
	ASSERT_EQ(0, _bst.getMin());
}
