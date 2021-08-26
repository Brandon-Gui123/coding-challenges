#include "my_functions.h"

#include <cassert>          // for assert macro
#include <iostream>
#include <string>

int main()
{
    std::string sampleFullText{ "aa_bb_cc_dd_bb_e" };
    std::string sampleSearchText{ "bb" };

    int count{ my_functions::getSubstringCount(sampleFullText, sampleSearchText) };

    assert(count == 2);

    std::cout << "Success!\n";

    return 0;
}
