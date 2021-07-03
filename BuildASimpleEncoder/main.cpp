#include <cassert>      // for assert()
#include <iostream>     // for console
#include <string>       // for std::string

// for the solution I wrote
#include "my_solution.h"

int main()
{
    const std::string firstInput{ "abc" };
    const std::string secondInput{ "zoo" };
    const std::string thirdInput{ "Alan" };

    const std::string firstOutput{ "123" };
    const std::string secondOutput{ "261515" };
    const std::string thirdOutput{ "112114" };

    assert(replaceCharWithAlphabetPositions(firstInput) == firstOutput);
    assert(replaceCharWithAlphabetPositions(secondInput) == secondOutput);
    assert(replaceCharWithAlphabetPositions(thirdInput) == thirdOutput);
    
    return 0;
}
