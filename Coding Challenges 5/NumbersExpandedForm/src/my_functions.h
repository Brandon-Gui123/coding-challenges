#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

#include <iostream>     // for std::cout
#include <vector>       // for std::vector

namespace my_functions
{
    template <typename T>
    void printVectorToStdOut(std::vector<T> v)
    {
        for (const auto& el : v)
        {
            std::cout << el << '\n';
        }
    }
}

#endif  // !MY_FUNCTIONS_H
