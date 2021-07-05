// for my solution
#include "my_solution.h"

#include <array>        // for std::array
#include <cassert>      // for assert()
#include <iostream>     // for console
#include <vector>       // for std::vector
#include <string>       // for std::string

int main()
{
    std::vector<std::string> strings
    {
        "ProgrammerPlus",
        "empowers",
        "you"
    };
    
    assert(getDifferenceBetweenLongestAndShortest(strings) == 11);

    std::array<std::string, 3> stringsInArray
    {
        "ProgrammerPlus",
        "empowers",
        "you"
    };

    assert(getDifferenceBetweenLongestAndShortest_Array(stringsInArray) == 11);

    return 0;
}
