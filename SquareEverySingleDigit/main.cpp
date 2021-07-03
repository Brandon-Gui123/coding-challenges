#include <cassert>      // for assert()
#include <iostream>     // for console

// for using my solution
#include "my_solution.h"

int main()
{
    assert(squareAllDigits(911) == 8111);
    assert(squareAllDigits(44) == 1616);
    assert(squareAllDigits(203) == 409);
    
    return 0;
}
