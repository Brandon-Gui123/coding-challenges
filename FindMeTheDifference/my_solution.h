#ifndef MY_SOLUTION_H
#define MY_SOLUTION_H

#include <cstddef>  // for std::size_t
#include <array>    // for std::array
#include <string>   // for std::string
#include <vector>   // for std::vector

int getDifferenceBetweenLongestAndShortest(const std::vector<std::string>& strings);

template <std::size_t size>
int getDifferenceBetweenLongestAndShortest_Array(const std::array<std::string, size>& strings)
{
    // Solution when dealing with an std::array.
    // Same as when dealing with a vector.
    throw "Not implemented!";
}

#endif  // !MY_SOLUTION_H
