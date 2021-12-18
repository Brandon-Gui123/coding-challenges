#include <iostream>     // for console
#include <vector>

#include "fibonacci_utils.h"
#include "string_number.h"

int main()
{
    std::vector<brandon_utils::string_number> sequences{ fibonacci::generate(99) };

    for (const auto& seq : sequences)
    {
        std::cout << seq.num << '\n';
    }

    return 0;
}
