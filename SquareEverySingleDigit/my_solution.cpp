#include <cmath>    // for std::pow
#include <string>   // for std::string stuff

int squareAllDigits(int number_to_use)
{
    // Fastest solution:
    // 1. Convert argument to a string.
    // 2. Iterate through each character.
    // 3. Convert character to a number.
    // 4. Square the number.
    // 5. Concatenate in a string variable
    // 6. Use std::stoi to convert string to int.
    // 7. Return that.

    std::string num_as_string{ std::to_string(number_to_use) };
    std::string result{ "" };

    for (const auto& num_char : num_as_string)
    {
        // so that we can do std::stoi
        std::string num_char_as_string{ num_char };

        // convert string to integer,
        // raise to a power of 2
        int squared{ 
            static_cast<int>(
                std::pow(
                    std::stoi(num_char_as_string),
                    2)
                )
        };

        // to combine squared values together
        // std::to_string required or we end up adding a char
        // based on the value of squared (which is used as an ASCII code)
        result += std::to_string(squared);
    }

    // string to integer
    return std::stoi(result);
}
