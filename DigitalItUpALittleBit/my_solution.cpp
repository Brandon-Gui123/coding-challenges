
#include <bitset>   // for std::bitset
#include <string>   // for std::string stuff

int getNumberOfOnesInBinary(int number)
{
    // Easiest to come up with:
    // 1. Create a bitset with the same number of 
    //    bits as an integer
    // 3. Count the number of times 1 appeared, which
    //    is a return value of true when accessed via
    //    operator[].
    // 4. Return that result.

    // sizeof returns size in bytes and 1 byte contains 8 bits
    // so we have to multiply by 8
    std::bitset<sizeof(unsigned int) * 8> numberBitset{ static_cast<unsigned int>(number) };

    int numOnes{ 0 };
    for (int i{ 0 }; i < numberBitset.size(); ++i)
    {
        if (numberBitset[i])
        {
            ++numOnes;
        }
    }

    return numOnes;
}

int getNumberOfOnesInBinary_Bitwise(int number)
{
    unsigned int unsignedNumber{ static_cast<unsigned int>(number) };

    int numOnes{ 0 };
    while (unsignedNumber != 0)
    {
        if (unsignedNumber & 1)
        {
            ++numOnes;
        }

        unsignedNumber = unsignedNumber >> 1;
    }

    return numOnes;
}
