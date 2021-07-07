// for the function that converts an integer to a vector of ints
#include "brandon_utils.h"

#include <iostream>     // for console
#include <vector>       // for std::vector

int main()
{
    std::vector<int> result{ brandon_utils::to_vector_of_digits(912391) };

    for (const int i : result)
    {
        std::cout << i << '\n';
    }

    return 0;
}
