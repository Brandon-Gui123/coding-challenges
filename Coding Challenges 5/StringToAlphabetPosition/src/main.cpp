#include "my_utils.h"

#include <cctype>
#include <iostream>
#include <string>

int main()
{
    // use the string example shown in the post
    std::string example{ "The sunset sets at twelve o' clock." };

    // remove all the characters that aren't alphabets
    std::string only_letters{ my_utils::remove_non_alpha(example) };

    // convert all uppercase characters to lowercase
    my_utils::to_lowercase(only_letters);

    // each element in the string is a character
    // we can use the ASCII table since each character
    // is mapped onto that
    // we subtract the value of the backtick char '`'
    // from the character to get a number corresponding
    // to the letter in the alphabet
    std::string alphabet_positions{};
    for (char letter : only_letters)
    {
        int letter_position{ my_utils::get_letter_pos(letter) };
        alphabet_positions += std::to_string(letter_position);

        // only add a space if the current letter isn't the last
        if (letter != *only_letters.rbegin())
        {
            alphabet_positions.push_back(' ');
        }
    }

    // print results
    std::cout << "In: " << example << '\n';
    std::cout << "Out: " << alphabet_positions << '\n';

    return 0;
}
