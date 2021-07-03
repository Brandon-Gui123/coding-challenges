#ifndef MY_SOLUTION_H
#define MY_SOLUTION_H

#include <string>   // for std::string
#include <unordered_map>    // for std::unordered_map

std::unordered_map<char, int> alphabetPositions
{
    { 'a', 1 }, { 'b', 2 }, { 'c', 3 }, { 'd', 4 }, { 'e', 5 },
    { 'f', 6 }, { 'g', 7 }, { 'h', 8 }, { 'i', 9 }, { 'j', 10 },
    { 'k', 11 }, { 'l', 12 }, { 'm', 13 }, { 'n', 14 }, { 'o', 15 },
    { 'p', 16 }, { 'q', 17 }, { 'r', 18 }, { 's', 19 }, { 't', 20 },
    { 'u', 21 }, { 'v', 22 }, { 'w', 23 }, { 'x', 24 }, { 'y', 25 },
    { 'z', 26 }
};

std::string replaceCharWithAlphabetPositions(const std::string& str);

#endif  // !MY_SOLUTION_H