#include <string>

bool contains5(int number_to_check)
{
    // Fastest solution that I can come up with
    // would be to convert the integer
    // to a string, and then searching for the
    // character '5'
    const std::string num_as_string{ std::to_string(number_to_check) };

    // the result is the position of the found character
    // or std::string::npos if no such character is found
    // see: https://en.cppreference.com/w/cpp/string/basic_string/find_first_of
    const size_t pos{ num_as_string.find_first_of('5') };

    return pos != std::string::npos;
}

bool contains5_alternative(int number_to_check)
{
    // Another solution that doesn't make use of
    // conversions to strings
    // 1. Modulo the arg by 10 to get the rightmost digit
    // 2. Check the first digit to see if it is a 5
    // 3. If it is, return true.
    // 4. If not, divide arg by 10 to remove the first digit
    // 5. Repeat until arg is 0.

    while (number_to_check > 0)
    {
        int rightmost{ number_to_check % 10 };

        if (rightmost == 5)
        {
            return true;
        }
        else
        {
            number_to_check /= 10;
        }
    }

    // if we're here, it means we can't find any 5s
    return false;
}
