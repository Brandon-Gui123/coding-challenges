#include "string_number.h"

#include <vector>           // for std::vector

namespace fibonacci
{
    std::vector<brandon_utils::string_number> generate(int count)
    {
        switch (count)
        {
            case 0:
                return {};

            case 1:
                return { brandon_utils::string_number{ 0 } };

            case 2:
                return { brandon_utils::string_number{ 0 }, brandon_utils::string_number{ 1 } };
        }

        std::vector<brandon_utils::string_number> fibonacci_numbers{ brandon_utils::string_number{ 0 }, brandon_utils::string_number{ 1 } };

        // start at 2 so we can access the previous 2 elements
        // without going out of bounds due to negative indices
        // count - 2 because the we are ignoring the first 2
        for (int i{ 2 }; i < count; ++i)
        {
            brandon_utils::string_number sum{ fibonacci_numbers[i - 2] + fibonacci_numbers[i - 1] };
            fibonacci_numbers.push_back(sum);
        }

        return fibonacci_numbers;
    }
}
