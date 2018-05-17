#ifndef EXERCISE3_DATA_CHECKED_H
#define EXERCISE3_DATA_CHECKED_H

#include <iostream>
#include <string>
#include <memory>

class Data
{


public:
std::shared_ptr<int> ptrData_;
    int size_;

    Data(int size)
        : ptrData_(new int[size], std::default_delete<int[]>()), size_(size)
    {
        for (int i = 0; i < size; ++i){
            ptrData_.get()[i] = i;
        }
    }

    ~Data()
    {
    }

    Data(const Data& right) : ptrData_(right.ptrData_), size_(right.size_)
    {
    }

std::function<const int *(void)> GetDataReader()
    {
        int *current_position = ptrData_.get();
        int *end_position = ptrData_.get() + size_;
        auto reader = [&]()->const int*
        {
            if(current_position == end_position)
            {
                return nullptr;
            }

            return current_position++;
        };

        return reader;
    }
};

#endif // EXERCISE3_DATA_CHECKED_H
