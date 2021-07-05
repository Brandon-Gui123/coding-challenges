#ifndef MY_SOLUTION_H
#define MY_SOLUTION_H

#include <cstddef>  // for std::size_t
#include <array>    // for std::array
#include <string>   // for std::string
#include <vector>   // for std::vector

int getDifferenceBetweenLongestAndShortest(const std::vector<std::string>& strings);

template <std::size_t size>
int getDifferenceBetweenLongestAndShortest(const std::array<std::string, size>& strings);

#endif  // !MY_SOLUTION_H
