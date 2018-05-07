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
	std::string Add(std::string lhs, std::string rhs)
	{
		lhs;
		rhs;
		std::string retval;
		return retval;
	}

	TEST_CASE("exercise5")
	{
		// enable to run exercise 6 tests
#if 0
		REQUIRE(Add("1", "2") == "3");

		std::string                       BigNum("1000000000000000000000000000000000000000000000000000000000000");
		REQUIRE(Add(std::move(BigNum), "1")   == "1000000000000000000000000000000000000000000000000000000000001");
		REQUIRE(Add(std::move(BigNum), "10")  == "1000000000000000000000000000000000000000000000000000000000010");
		REQUIRE(Add(std::move(BigNum), "100") == "1000000000000000000000000000000000000000000000000000000000100");
#endif
	}
}
