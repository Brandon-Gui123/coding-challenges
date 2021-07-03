#include <string>

bool contains5(int number_to_check)
{
    // Fastest solution that I can come up with
    // would be to convert the integer
    // to a string, and then searching for the
    // character '5'
    std::string num_as_string{ std::to_string(number_to_check) };

    // the result is the position of the found character
    // or std::string::npos if no such character is found
    // see: https://en.cppreference.com/w/cpp/string/basic_string/find_first_of
    size_t pos{ num_as_string.find_first_of('5') };

    return pos != std::string::npos;
}
