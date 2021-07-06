
#include "morse_code_letter.h"      // for MorseCodeLetter struct
#include "morse_code_tables.h"      // for array of morse codes

#include <cctype>                   // for std::toupper

const MorseCodeLetter* findMorseCodeLetterWithCharacter(char ch)
{
    for (const auto& morseCodeLetter : International::morseCodesLetters)
    {
        // need to convert to uppercase since that is the characters
        // we use in the array
        if (morseCodeLetter.letter == std::toupper(ch))
        {
            return &morseCodeLetter;
        }
    }

    return nullptr;
}

const MorseCodeLetter* findMorseCodeLetterWithCode(const std::string& code)
{
    for (const auto& morseCodeLetter : International::morseCodesLetters)
    {
        if (morseCodeLetter.morseCode == code)
        {
            return &morseCodeLetter;
        }
    }

    return nullptr;
}

std::string charToMorseCode(char ch)
{
    const MorseCodeLetter* morseCodeLetter{ findMorseCodeLetterWithCharacter(ch) };
    return morseCodeLetter->morseCode;
}
