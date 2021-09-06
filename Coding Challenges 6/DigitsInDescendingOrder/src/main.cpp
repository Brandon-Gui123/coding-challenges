#include <functional>   // for std::greater
#include <iostream>
#include <vector>       // for std::vector

int asDescending(int number)
{
    std::vector<int> digits{};
    int numberCopy{ number };
    do
    {
        digits.push_back(numberCopy % 10);
        numberCopy /= 10;
    } while (numberCopy != 0);

    std::sort(digits.begin(), digits.end(), std::greater{});

    int result{ 0 };
    int multiplier{ 1 };
    for (auto it{ digits.rbegin() }; it != digits.rend(); ++it)
    {
        result += *it * multiplier;
        multiplier *= 10;
    }

    return result;
}

int main()
{
    // The easiest would be to use a vector to store the digits of a number,
    // then sort those digits in descending order.
    // Then combine all those digits together and return the result as an integer.

    int input{ 21445 };
    int result{ asDescending(input) };
    std::cout << input << "\t==>\t" << result << '\n';
    return 0;
}
