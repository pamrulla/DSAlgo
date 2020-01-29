#include "ArraysAndStrings.h"
#include "gtest/gtest.h"

using namespace ::testing;
using namespace CCI::ArraysAndStrings;

TEST(ArraysAndStringsTests, IsUnique) {
	EXPECT_TRUE(IsUnique("abcd"));
	EXPECT_TRUE(IsUnique("aA"));
	EXPECT_FALSE(IsUnique("aab"));
}

TEST(ArraysAndStringsTests, checkPermutation) {
	EXPECT_TRUE(checkPermutation("abcd", "dcba"));
	EXPECT_FALSE(checkPermutation("abcd", "ergd"));
	EXPECT_FALSE(checkPermutation("abcd", "abcde"));
	EXPECT_TRUE(checkPermutation("abad", "aadb"));
}

TEST(ArraysAndStringsTests, URLify) {
	std::string str = "Mr John Smith ";
	URLify(str);
	EXPECT_EQ(str, "Mr%20John%20Smith");
	str = "   Mr John Smith ";
	URLify(str);
	EXPECT_EQ(str, "Mr%20John%20Smith");
}

TEST(ArraysAndStringsTests, stringCompression) {
	EXPECT_EQ(stringCompression("aabcccccaaa"), "a2b1c5a3");
}

TEST(ArraysAndStringsTests, palindromePermutation) {
	EXPECT_TRUE(palindromePermutation("tact coa"));
	EXPECT_FALSE(palindromePermutation("tacat coa"));
}

TEST(ArraysAndStringsTests, zeroMatrix) {
	int a[3][3] = {
		{1, 2, 3},
		{4, 0, 6},
		{7, 8, 9}
	};
	int exp[3][3] = {
		{1, 0, 3},
		{0, 0, 0},
		{7, 0, 9}
	};
	zeroMatrix((int*)a, 3, 3);
	EXPECT_EQ(0, memcmp(a, exp, sizeof(int) * 3 * 3));
}
