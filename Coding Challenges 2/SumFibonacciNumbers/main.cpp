#include <iostream>     // for console

#include "fibonacci_utils.h"

int main()
{
    std::vector<long double> fibonacci_sequence{ fibonacci::generate(20) };

    std::cout.precision(100);

    long double sum{ 0 };
    for (const auto num : fibonacci_sequence)
    {
        std::cout << num << '\n';
        sum += num;
    }

    std::cout << "Sum: " << sum << '\n';
    
    return 0;
}
