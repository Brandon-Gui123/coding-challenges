#include "morse_code_tables.h"  // for morse code mappings

#include <cctype>   // for std::tolower
#include <string>   // for std::string

std::string stringToMorseCode(const std::string& string)
{
    std::string morseCode{ "" };

    for (const char ch : string)
    {
        if (ch == ' ')
        {
            morseCode += "  ";
            continue;
        }

        const char lowerCh{ static_cast<char>(std::tolower(ch)) };
        auto ptrToCh{ International::morseCodesForLetter.find(lowerCh) };

        if (ptrToCh == International::morseCodesForLetter.end())
        {
            // no such key found!
            // we'll use a question mark then
            morseCode += "???? ";
            continue;
        }
        else
        {
            morseCode += ptrToCh->second + " ";
        }
    }

    return morseCode;
}

std::string morseCodeToString(const std::string& morseCode)
{
    throw "Unimplemented function";
}
