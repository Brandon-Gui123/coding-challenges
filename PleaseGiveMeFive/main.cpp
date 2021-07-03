#include <cassert>      // for assert()
#include <iostream>     // for console

// for the solution I wrote
#include "my_solution.h"

int main()
{
    assert(contains5(51) == true);
    assert(contains5(200) == false);
    assert(contains5(555) == true);
    
    return 0;
}
