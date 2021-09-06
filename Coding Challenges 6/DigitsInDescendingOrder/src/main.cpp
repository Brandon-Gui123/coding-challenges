#include <functional>   // for std::greater
#include <iostream>
#include <vector>       // for std::vector

int main()
{
    // The easiest would be to use a vector to store the digits of a number,
    // then sort those digits in descending order.
    // Then combine all those digits together and return the result as an integer.

    int input{ 21445 };

    // 1. Store each digit in a vector by using the % and / operators
    //      - do num % 10 to extract the rightmost digit and store it in the vector
    //        (order doesn't matter, since we will be sorting later)
    //      - do num / 10 to remove the rightmost digit, moving all other digits to the right by one space
    //      - continue until input is 0
    std::vector<int> digits{};
    int inputCopy{ input };
    do
    {
        digits.push_back(inputCopy % 10);
        inputCopy /= 10;
    }
    while (inputCopy != 0);

    // 2. We can use std::sort to sort the numbers in descending order
    //    To do this, we give the function a function pointer (or a lambda would work too)
    std::sort(digits.begin(), digits.end(), std::greater{});
    
    // 3. To reconstruct the number, we can use rbegin() and rend() to iterate the vector backwards.
    //    The digit is then multiplied by a multiplier that gets multiplied by 10 every iteration.
    int result{ 0 };
    int multiplier{ 1 };
    for (auto it{ digits.rbegin() }; it != digits.rend(); ++it)
    {
        result += *it * multiplier;
        multiplier *= 10;
    }

    std::cout << input << "\t==>\t" << result << '\n';
    return 0;
}
