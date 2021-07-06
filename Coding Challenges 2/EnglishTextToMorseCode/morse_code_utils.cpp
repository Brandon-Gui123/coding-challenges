#include "morse_code_constants.h"   // for dot and dash compile-time constants
#include "morse_code_letter.h"      // for MorseCodeLetter struct
#include "morse_code_tables.h"      // for array of morse codes
#include "morse_code_utils.h"       // for functions here to know each other

#include <algorithm>                // for std::replace_if
#include <cctype>                   // for std::toupper
#include <string>                   // for std::string

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

std::string charToMorseCode(char ch, char dotCh, char dashCh)
{
    const MorseCodeLetter* morseCodeLetter{ findMorseCodeLetterWithCharacter(ch) };
    std::string morseCode{ morseCodeLetter->morseCode };

    std::replace(morseCode.begin(), morseCode.end(), '0', dotCh);
    std::replace(morseCode.begin(), morseCode.end(), '1', dashCh);

    return morseCode;
}

char morseCodeToChar(const std::string& morseCode, char dotCh, char dashCh)
{
    std::string morseCodeOriginalFormat{ morseCode };
    std::replace(morseCodeOriginalFormat.begin(), morseCodeOriginalFormat.end(), dotCh, '0');
    std::replace(morseCodeOriginalFormat.begin(), morseCodeOriginalFormat.end(), dashCh, '1');

    const MorseCodeLetter* morseCodeLetter{ findMorseCodeLetterWithCode(morseCodeOriginalFormat) };
    return morseCodeLetter->letter;
}

std::string stringToMorseCode(const std::string& str, char dotCh, char dashCh)
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
            morseCode += charToMorseCode(*chPtr, dotCh, dashCh);
        }

        // not the last element?
        if (chPtr != str.end() - 1)
        {
            morseCode += ' ';
        }
    }

    return morseCode;
}

std::string morseCodeToString(const std::string& morseCode, char dotCh, char dashCh)
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
                str += morseCodeToChar(morseCodeSet, dotCh, dashCh);
                morseCodeSet = "";
            }

            ++whitespacesEncounteredInARow;
        }
        else if (chPtr == morseCode.end() - 1)  // last element
        {
            morseCodeSet += *chPtr;
            str += morseCodeToChar(morseCodeSet, dotCh, dashCh);
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