#include <cctype>   // for std::tolower
#include <string>   // for std::string

std::string replaceCharWithAlphabetPositions(const std::string& str)
{
    /*
     * We can simply use the ASCII table to get the character's position
     * in the alphabet.
     * This reduces the need for an unordered map storing all the mappings.
     */

    std::string result{ "" };

    // the string would be at least as big as the input string
    // so might as well reserve some size for performance
    // (no need to resize a lot when we append chars)
    result.reserve(str.size());

    for (auto ch : str)
    {
        ch = std::tolower(ch);

        // 'a' is the first character in the ASCII table from 'a' to 'z'
        // so subtracting 'a' results in a range from 0 to 25.
        // adding a 1 changes the range from 1 to 26, which makes sense since
        // we intend to say first, second, third, fourth etc.
        int alphabetPos{ ch - 'a' + 1 };

        result += std::to_string(alphabetPos);
    }

    return result;
}
