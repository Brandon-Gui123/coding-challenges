#include <vector>           // for std::vector

namespace fibonacci
{
    std::vector<int> generate(int count)
    {
        switch (count)
        {
            case 0:
                return {};

            case 1:
                return { 0 };

            case 2:
                return { 0, 1 };
        }

        std::vector<int> fibonacci_numbers{ 0, 1 };

        // start at 2 so we can access the previous 2 elements
        // without going out of bounds due to negative indices
        // count - 2 because the we are ignoring the first 2
        for (int i{ 2 }; i < count - 2; ++i)
        {
            int sum{ fibonacci_numbers[i - 2] + fibonacci_numbers[i - 1] };
            fibonacci_numbers.push_back(sum);
        }

        return fibonacci_numbers;
    }
}
