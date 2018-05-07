/*
 * You've been assigned to code review some code from a Junior Developer. Your assignment is to give the developer clear
 *  feedback on areas where their code needs improvement.
 * 
 * In a separate document, please enumerate each issue you find in the code. First, list the line number it occurs on, then
 *  describe the issue. Next, describe a proposed solution for that specific code issue. The solution may affect other lines
 *  of code as well, but you should still address issues you find on other lines of code. For this section of the exercise,
 *  assume that the class `Data` serves some larger code reusability purpose within the code base.
 * 
 * After listing issues with individual lines of code, please conclude with any comments on overarching design concerns and
 *  specific refactors that you suggest. You may make suggestions on the design of the `Data` class (for reuse elsewhere in
 *  the code base), and you may also make suggestions regarding this specific executable in isolation from the rest of the
 *  code base (i.e. you may propose an alternative design for reading values from `fill` and printing them to standard out).
 *
 * You have two overarching goals;
 *  1) help the junior developer understand how to write each individual line of code better. This is mostly an objective problem.
 *  2) help the junior developer come up with a better overall design to solve the problem. This is a more subjective problem.
 * 
 * For purposes of this exercise, consider the contents of `fill.h` to be a pre-existing API that will not be modified.
 */

#include "exercise3_fill.h"
#include "exercise3_data.h"

#include <iostream>
#include <exception>

void exercise3()
{
    //Get 64 numbers of data
    Data data{64};

    //Then use the reader to print the data
    auto reader = data.GetDataReader();
    int value = reader();
    while(value != -1)
    {
        std::cout << value << '\n';

        value = reader();
    }
}

// this is just a placeholder to make the exercise link
// in the real project it would be implemented elsewhere
int fill(int *ptr, int size) noexcept(false)
{
	throw std::runtime_error("Not implemented");
}
