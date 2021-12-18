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

    // An array of pointers to constant chars
    const char* stringsInCharPointers[]
    {
        "ProgrammerPlus",
        "empowers",
        "you"
    };

    assert(
        getDifferenceBetweenLongestAndShortest_CharPointer(
            &stringsInCharPointers[0],                                  // memory address of the first element
            &stringsInCharPointers[std::size(stringsInCharPointers)])   // memory address of the element after the last
        == 11
    );

    return 0;
}
