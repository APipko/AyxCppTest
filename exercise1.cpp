#include "catch/catch.hpp" 
#include <memory>
#include "spatial.h"
#include <iostream>

namespace AyxCppTest
{
	// exercise 1
	// tasks
	//		Fix the provided code so all the tests pass (do not edit the tests)
	//
	// More Informaion
	//		some simple spatial geometry classes have been provided. This was written
	//		with TDD and the tests below were written and verified by the team but they don't all pass.


	TEST_CASE("exercise1")
	{
		// enable to run exercise 1 tests
#if 1
		{
			std::unique_ptr<Area> p = std::make_unique<Circle>(Point{ 1,1 }, 2);

			// test a point near the center of the circle well inside the radius
			CHECK(p->Contains(Point{ 1.1, 1.1 }));

			// the border should be outside
			CHECK(!p->Contains(Point{ -1, 1 }));
		}

		{
			std::unique_ptr<Area> p = std::make_unique<Rectangle>(Point{ 1,1 }, Point{ 2,2 });

			// the border should be outside
			CHECK(!p->Contains(Point{ 2, 2 }));

			// test a point in the middle of the rectangle
			CHECK(p->Contains(Point{ 1.5, 1.5 }));


		}

		// test for any memory leaks
		CHECK(!Point::DbgHasLeaks());
#endif
	}
}
