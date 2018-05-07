#include "catch/catch.hpp" 
#include "Add.h"

namespace AyxCppTest
{
	/**
	* Add two arbitrarily long numbers encoded as strings and return the result
	* as a number encoded as a string.  Each character in the input and output
	* strings is a single digit in the range of [0,9] inclusive.
	*
	* Sample test cases are provided as a starting point.
	*
	* Tasks:
	*   -Complete the Add function.
	*   -Add and repair test cases as appropriate.
	*/

    int CharToDigit(char ch){
        return ch - 48;
    }

    char DigitToChar(int digit){
        return digit + 48;
    }

//    std::string Add(const char* lhs, const char* rhs){
//        return Add(std::string(lhs), std::string(rhs));
//    }

    std::string Add(std::string lhs, std::string rhs)
	{

        auto leftDigit = lhs.rbegin();
        auto rightDigit = rhs.rbegin();
        auto leftEnd = lhs.rend();
        auto rightEnd = rhs.rend();

        if (lhs.size() < rhs.size()){
            leftDigit = rhs.rbegin();
            rightDigit = lhs.rbegin();
            leftEnd = rhs.rend();
            rightEnd = lhs.rend();
        }

        int overflow = 0;
        std::string sumString;

        while (rightDigit != rightEnd) {
            auto digitSum = CharToDigit(*leftDigit) + CharToDigit(*rightDigit) + overflow;
            overflow = digitSum / 10;
            sumString.push_back(DigitToChar(digitSum % 10));
            ++leftDigit;
            ++rightDigit;
        }
        while (leftDigit != leftEnd) {
            auto digitSum = CharToDigit(*leftDigit) + overflow;
            overflow = digitSum / 10;
            sumString.push_back(DigitToChar(digitSum % 10));
            ++leftDigit;
        }
        if (overflow > 0){
            sumString.push_back('1');
        }

        std::reverse(sumString.begin(), sumString.end());
        return sumString;
	}

	TEST_CASE("exercise5")
	{
		// enable to run exercise 6 tests
#if 1
		REQUIRE(Add("1", "2") == "3");

        std::string                       BigNum("1000000000000000000000000000000000000000000000000000000000000");
        REQUIRE(Add(BigNum, "1")   == "1000000000000000000000000000000000000000000000000000000000001");
        REQUIRE(Add(BigNum, "10")  == "1000000000000000000000000000000000000000000000000000000000010");
        REQUIRE(Add(BigNum, "100") == "1000000000000000000000000000000000000000000000000000000000100");
        REQUIRE(Add("999", "1") == "1000");
        REQUIRE(Add("99", "99") == "198");
        REQUIRE(Add("1", "999") == "1000");
        REQUIRE(Add("119", "5") == "124");
#endif
	}
}
