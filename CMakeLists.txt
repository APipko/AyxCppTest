Project(AyxCppTest)

set (CMAKE_CXX_STANDARD 14)

add_executable(AyxCppTest 
	Add.h
	exercise1.cpp 
	exercise2.cpp 
	exercise2.png # not actual source - just here for information
        polygon.h
        polygon.cpp
	exercise3.cpp
	exercise3_fill.h
	exercise3_data.h
	exercise4.cpp
	exercise5.cpp
	exercise6.cpp
	spatial.cpp
	spatial.h
	main.cpp
	catch/catch.hpp)

target_link_libraries(AyxCppTest pthread)
