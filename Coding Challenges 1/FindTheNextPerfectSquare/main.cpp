#include <cassert>          // for assert()
#include <iostream>         // for console

// for running and checking my solution to the challenge
#include "my_solution.h"

int main()
{
    assert(get_next_perfect_square(25) == 36);
    assert(get_next_perfect_square(81) == 100);
    assert(get_next_perfect_square(40) == -1);

    return 0;
}
