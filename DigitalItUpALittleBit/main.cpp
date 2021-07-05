// for the solutions I wrote
#include "my_solution.h"

#include <cassert>      // for assert()
#include <iostream>     // for console

int main()
{
    assert(getNumberOfOnesInBinary(32) == 1);
    assert(getNumberOfOnesInBinary(31) == 5);
    assert(getNumberOfOnesInBinary(5) == 2);
    
    return 0;
}
