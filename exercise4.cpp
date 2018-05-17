#include "catch/catch.hpp" 
#include <memory>
#include <array>
#include <thread>
#include "spatial.h"
#include <atomic>
#include <mutex>

namespace AyxCppTest
{
	// excersize 4
	// tasks
	//		Fix the provided class RectangleSizeCounter so all the tests pass (do not edit the tests)
	//			FYI - it is important to get proper multi-threading, so there are some performance based tests as well
	//

	namespace
	{
		class RectangleSizeCounter
		{
		private:
            double m_nTotalSize{ 0 };
            std::mutex counterMutex_;
		public:
			RectangleSizeCounter();
			void AddRectangle(Rectangle rect);
			double GetTotalSize();
		};

		RectangleSizeCounter::RectangleSizeCounter()
		{
		}

		void RectangleSizeCounter::AddRectangle(Rectangle rect)
        {
            double rectSize = rect.Size();

            std::lock_guard<std::mutex> guard(counterMutex_);
            m_nTotalSize = m_nTotalSize + rectSize;
		}

		double RectangleSizeCounter::GetTotalSize()
		{
            std::lock_guard<std::mutex> guard(counterMutex_);
            auto value = m_nTotalSize;
            return value;
		}

	}

	TEST_CASE("exercise4")
	{
		// enable to run exercise 4 tests
#if 1
		std::array<Rectangle, 4> rectangles{ Rectangle{ Point{ 1,1 }, Point{ 2,2 } },
			Rectangle{ Point{ 2,2 }, Point{ 4,4 } },
			Rectangle{ Point{ 1,1 }, Point{ 3,2 } },
			Rectangle{ Point{ 1,1 }, Point{ 2,2 } } };

		{
			RectangleSizeCounter counter;
			counter.AddRectangle(rectangles[0]);
			counter.AddRectangle(rectangles[1]);
			counter.AddRectangle(rectangles[2]);
			counter.AddRectangle(rectangles[3]);

			REQUIRE(counter.GetTotalSize() == 8.0);
		}
		
		auto b = std::chrono::system_clock::now();
        for (unsigned nTry = 0; nTry<20; ++nTry)
		{
			RectangleSizeCounter counter;

			const int num_threads{ 4 };
			std::thread t[num_threads];

			for (int i = 0; i < num_threads; ++i)
				t[i] = std::thread([&counter, &rectangles, i]() {counter.AddRectangle(rectangles[i]); });

			for (int i = 0; i < num_threads; ++i)
				t[i].join();

			REQUIRE(counter.GetTotalSize() == 8.0);
		}
		REQUIRE(std::chrono::milliseconds(400) > std::chrono::system_clock::now() - b);
		REQUIRE(std::chrono::milliseconds(100) < std::chrono::system_clock::now() - b);

#endif
	}
}
