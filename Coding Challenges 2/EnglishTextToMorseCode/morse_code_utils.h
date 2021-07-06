#ifndef MORSE_CODE_UTILS_H
#define MORSE_CODE_UTILS_H

#include "morse_code_tables.h"  // for the array of morse codes
#include "morse_code_letter.h"  // for MorseCodeLetter struct

#include <string>               // for std::string

const MorseCodeLetter* findMorseCodeLetterWithCharacter(char ch);
const MorseCodeLetter* findMorseCodeLetterWithCode(const std::string& code);

std::string charToMorseCode(char ch);
char morseCodeToChar(const std::string& morseCode);

std::string stringToMorseCode(const std::string& str);

#endif  // !MORSE_CODE_UTILS_H
