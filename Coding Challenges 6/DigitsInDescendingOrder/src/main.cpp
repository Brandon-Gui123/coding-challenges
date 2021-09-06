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
    std::cout << 21445 << "\t==>\t" << asDescending(21445) << '\n';
    std::cout << 145263 << "\t==>\t" << asDescending(145263) << '\n';
    
    return 0;
}
