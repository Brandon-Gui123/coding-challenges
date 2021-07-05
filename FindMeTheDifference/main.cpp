// for my solution
#include "my_solution.h"

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
    
    return 0;
}
