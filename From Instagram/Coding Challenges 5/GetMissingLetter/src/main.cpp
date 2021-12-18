#include "my_functions.h"

#include <cassert>      // for assert() macro
#include <iostream>
#include <vector>       // for std::vector

int main()
{
    // let's assume our input is the same as the example provided in the post
    std::vector<char> exampleInput{ 'a', 'b', 'c', 'd', 'f' };

    char missingChar{ my_functions::findMissingLetter(exampleInput) };

    std::cout << "The missing char is " << missingChar << '\n';

    return 0;
}
