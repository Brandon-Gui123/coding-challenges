
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

char morseCodeToChar(const std::string& morseCode)
{
    const MorseCodeLetter* morseCodeLetter{ findMorseCodeLetterWithCode(morseCode) };
    return morseCodeLetter->letter;
}

std::string stringToMorseCode(const std::string& str)
{
    std::string morseCode{ "" };

    for (auto chPtr{ str.begin() }; chPtr != str.end(); ++chPtr)
    {
        if (*chPtr == ' ')
        {
            morseCode += ' ';
        }
        else
        {
            morseCode += charToMorseCode(*chPtr);
        }

        // not the last element?
        if (chPtr != str.end() - 1)
        {
            morseCode += ' ';
        }
    }

    return morseCode;
}

std::string morseCodeToString(const std::string& morseCode)
{
    std::string str{ "" };
    int whitespacesEncounteredInARow{ 0 };
    std::string morseCodeSet{ "" };

    for (auto chPtr{ morseCode.begin() }; chPtr != morseCode.end(); ++chPtr)
    {
        if (*chPtr == ' ')
        {
            if (morseCodeSet != "")
            {
                str += morseCodeToChar(morseCodeSet);
                morseCodeSet = "";
            }

            ++whitespacesEncounteredInARow;
        }
        else if (chPtr == morseCode.end() - 1)  // last element
        {
            morseCodeSet += *chPtr;
            str += morseCodeToChar(morseCodeSet);
        }
        else
        {
            whitespacesEncounteredInARow = 0;
            morseCodeSet += *chPtr;
        }

        if (whitespacesEncounteredInARow >= 3)
        {
            // this is a space
            whitespacesEncounteredInARow = 0;
            str += ' ';
        }
    }

    return str;
}
