#include "morse_code_utils.h"

#include <iostream>     // for console

int main()
{
    std::string morse{ stringToMorseCode("HELLO WORLD", '*', '_')};
    std::cout << morse << '\n';
    std::cout << morseCodeToString(morse, '*', '_') << '\n';

    return 0;
}
