#include <vector>           // for std::vector

std::vector<int> to_vector_of_digits(int number)
{
    std::vector<int> digits{};

    do
    {
        const int last_digit{ number % 10 };
        digits.insert(digits.begin(), last_digit);

        // remove last digit from the number
        number /= 10;
    }
    while (number != 0);

    return digits;
}
