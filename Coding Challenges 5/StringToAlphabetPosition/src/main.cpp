#include <cctype>
#include <iostream>
#include <string>

int main()
{
    // use the string example shown in the post
    std::string example{ "The sunset sets at twelve o' clock." };

    // remove all the characters that aren't alphabets
    std::string onlyLetters{};
    for (char letter : example)
    {
        if (std::isalpha(letter))
        {
            onlyLetters.push_back(letter);
        }
    }

    // convert all uppercase characters to lowercase
    std::string lowercaseLetters{};
    for (char letter : onlyLetters)
    {
        lowercaseLetters.push_back(std::tolower(letter));
    }

    // each element in the string is a character
    // we can use the ASCII table since each character
    // is mapped onto that
    // we subtract the value of the backtick char '`'
    // from the character to get a number corresponding
    // to the letter in the alphabet
    std::string alphabetPositionings{};
    for (char letter : lowercaseLetters)
    {
        int letterPosition{ letter - '`' };
        alphabetPositionings += std::to_string(letterPosition);

        // only add a space if the current letter isn't the last
        if (letter != *lowercaseLetters.rend())
        {
            alphabetPositionings.push_back(' ');
        }
    }

    // print results
    std::cout << "In: " << example << '\n';
    std::cout << "Out: " << alphabetPositionings << '\n';

    return 0;
}
