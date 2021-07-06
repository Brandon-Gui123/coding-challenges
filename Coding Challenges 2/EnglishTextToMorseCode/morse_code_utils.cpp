
#include "morse_code_letter.h"      // for MorseCodeLetter struct
#include "morse_code_tables.h"      // for array of morse codes

const MorseCodeLetter* findMorseCodeLetterWithCharacter(char ch)
{
    for (const auto& morseCodeLetter : International::morseCodesLetters)
    {
        if (morseCodeLetter.letter == ch)
        {
            return &morseCodeLetter;
        }
    }

    return nullptr;
}
