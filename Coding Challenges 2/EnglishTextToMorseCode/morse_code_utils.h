#ifndef MORSE_CODE_UTILS_H
#define MORSE_CODE_UTILS_H

#include "morse_code_constants.h"   // for dot and dash compile-time constants
#include "morse_code_tables.h"      // for the array of morse codes
#include "morse_code_letter.h"      // for MorseCodeLetter struct

#include <string>               // for std::string

const MorseCodeLetter* findMorseCodeLetterWithCharacter(char ch);
const MorseCodeLetter* findMorseCodeLetterWithCode(const std::string& code);

std::string charToMorseCode(char ch, char dotCh = MorseCodeConstants::dot, char dashCh = MorseCodeConstants::dash);
char morseCodeToChar(const std::string& morseCode, char dotCh = MorseCodeConstants::dot, char dashCh = MorseCodeConstants::dash);

std::string stringToMorseCode(const std::string& str, char dotCh = MorseCodeConstants::dot, char dashCh = MorseCodeConstants::dash);
std::string morseCodeToString(const std::string& morseCode, char dotCh = MorseCodeConstants::dot, char dashCh = MorseCodeConstants::dash);

#endif  // !MORSE_CODE_UTILS_H
