#ifndef MORSE_CODE_TABLES_H
#define MORSE_CODE_TABLES_H

#include "morse_code_letter.h"  // for MorseCodeLetter struct

#include <array>            // for std::array
#include <string>           // for std::string

namespace International
{
    const std::array<MorseCodeLetter, 45> morseCodesLetters
    {
        'A', "01",
        'B', "1000",
        'C', "1010",
        'D', "100",
        'E', "0",
        'F', "0010",
        'G', "110",
        'H', "0000",
        'I', "00",
        'J', "0111",
        'K', "101",
        'L', "0100",
        'M', "11",
        'N', "10",
        'O', "111",
        'P', "0110",
        'Q', "1101",
        'R', "010",
        'S', "000",
        'T', "1",
        'U', "001",
        'V', "0001",
        'W', "011",
        'X', "1001",
        'Y', "1011",
        'Z', "1100",
        '1', "01111",
        '2', "00111",
        '3', "00011",
        '4', "00001",
        '5', "00000",
        '6', "10000",
        '7', "11000",
        '8', "11100",
        '9', "11110",
        '0', "11111",
        ',', "110011",
        '.', "010101",
        '?', "001100",
        ';', "10101",
        ':', "111000",
        '/', "10010",
        '-', "100001",
        '\'', "011110",
        '_', "001101"
    };
}

#endif  // !MORSE_CODE_TABLES_H
