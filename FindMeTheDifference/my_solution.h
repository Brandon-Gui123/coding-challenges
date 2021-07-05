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

    size_t shortestLength{ strings[0].length() };
    size_t longestLength{ strings[0].length() };

    for (const std::string& str : strings)
    {
        if (str.length() < shortestLength)
        {
            shortestLength = str.length();
        }

        if (str.length() > longestLength)
        {
            longestLength = str.length();
        }
    }

    return longestLength - shortestLength;
}

int getStringLength(const char* charPointer);

// Pointer to a pointer of a constant char.
// A string is an array of constant characters (remember that strings by right are immutable).
// An array of strings is an array of an array of constant characters.
// In this function, we want a pointer to the first element in the array of strings.
// The first element is of type const char*, using the address-of operator here will yield
// a type of const char** (a pointer to a pointer to a const character).
int getDifferenceBetweenLongestAndShortest_CharPointer(const char** begin, const char** end);

#endif  // !MY_SOLUTION_H
