#pragma once

#include <functional>

//This method is defined elsewhere, and will be pulled in by the linker
int fill(int *ptr, int size) noexcept(false);

//This method is not used by our program; it is consumed by other files, irrelevant to this exercise
int fill(std::function<void(int)> to_fill, int size) noexcept(false);
