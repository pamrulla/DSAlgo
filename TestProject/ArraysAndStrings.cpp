#include "ArraysAndStrings.h"
#include <map>
#include <sstream>
#include <string>
//All the problems in Arrays And Strings chapter


namespace CCI {
	namespace ArraysAndStrings {
		bool IsUnique(std::string str)
		{
			std::map<char, bool> hash;

			for (auto i = 0; i < str.length(); ++i) {
				if (hash.find(str[i]) != hash.end()) {
					return false;
				}
				hash[str[i]] = true;
			}

			return true;
		}
		bool checkPermutation(std::string one, std::string two)
		{
			if (one.length() != two.length()) {
				return false;
			}
			auto one_value = 0;
			auto two_value = 0;
			for (auto i = 0; i < one.length(); ++i) {
				one_value |= one[i];
				two_value |= two[i];
			}
			return one_value == two_value;
		}
		void URLify(std::string& str)
		{
			const std::string replaceString = "%20";
			std::string temp = "";
			auto spacesCount = 0;
			bool isStartingChar = true;
			for (auto ch : str) {
				if (ch == ' ') {
					++spacesCount;
				}
				else {
					if (isStartingChar) {
						spacesCount = 0;
						isStartingChar = false;
					}
					while (spacesCount) {
						--spacesCount;
						temp += replaceString;
					}
					temp += ch;
				}
			}
			str = temp;
		}
		bool palindromePermutation(std::string str)
		{
			std::map<char, int> hash;
			bool isOdd = false;

			for (auto ch : str) {
				if (ch == ' ') {
					continue;
				}
				if (hash.find(ch) == hash.end()) {
					hash[ch] = 1;
				}
				else {
					++hash[ch];
				}
			}

			for (auto item : hash) {
				if (item.second % 2 == 1) {
					if (isOdd) {
						return false;
					}
					isOdd = true;
				}
			}

			return true;
		}
		std::string stringCompression(std::string str)
		{
			std::ostringstream result;
			char prev = str[0];
			result << prev;
			int count = 1;
			for (auto i = 1; i < str.length(); ++i) {
				if (prev != str[i]) {
					result << count;
					count = 1;
					prev = str[i];
					prev = str[i];
					result << prev;
				}
				else {
					++count;
				}
			}
			result << count;
			return result.str();
		}
		void zeroMatrix(int* a, const int m, const int n)
		{
			int *temp = new int[m * n];
			memcpy(temp, a, sizeof(int) * m * n);
			for (auto i = 0; i < m; ++i) {
				for (auto j = 0; j < n; ++j) {
					if (*((a + i * n) + j) == 0) {
						//Zero out ith row
						for (auto k = 0; k < n; ++k) {
							*((temp + i * n) + k) = 0;
						}
						//Zero out jth column
						for (auto k = 0; k < m; ++k) {
							*((temp + k * n) + j) = 0;
						}
					}
				}
			}
			memcpy(a, temp, sizeof(int) * m * n);
		}
	}
}
