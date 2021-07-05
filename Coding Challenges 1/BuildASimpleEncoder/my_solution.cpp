// for the unordered map
#include "constants.h"

#include <cctype>   // for std::tolower
#include <string>
#include <unordered_map>

std::string replaceCharWithAlphabetPositions(const std::string& str)
{
    // Fastest that I can come up with:
    // 1. Iterate through each character in the string
    // 2. Convert the character to lowercase, if needed
    // 3. Use a map that has chars as the key and ints as the value.
    //    Ordered from a to z, with ints as the position on the alphabet.
    // 4. With the current character, pass it into the map as the key.
    //    The returned value will be the position of the char on the alphabet.
    // 5. Convert the int into a string.
    // 6. Concatenate it with some variable that holds result.
    // 7. Return the result after iterating through all of the chars.

    std::string result{ "" };

    for (auto ch : str)
    {
        ch = std::tolower(ch);

        int alphabetPos{ alphabetPositions[ch] };

        result += std::to_string(alphabetPos);
    }

    return result;
}
