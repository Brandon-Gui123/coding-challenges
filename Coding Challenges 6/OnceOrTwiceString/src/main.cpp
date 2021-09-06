#include <iostream>
#include <string>               // for std::string
#include <unordered_map>        // for std::unordered_map

std::string replaceOnceTwice(const std::string& input)
{
    std::unordered_map<char, int> charactersTable{};

    for (const char ch : input)
    {
        // note that if the key 'ch' doesn't exist, it will be created
        charactersTable[ch] += 1;
    }

    // make a copy of the input so we don't modify the original
    std::string inputCopy{ input };
    
    for (char& ch : inputCopy)
    {
        // 5. Use the character as a key for the map to get the value
        int numOccurrences{ charactersTable[ch] };

        // 6. Check if the value is 1
        if (numOccurrences == 1)
        {
            // - If the value is 1, change current char to '('
            ch = '(';
        }
        else
        {
            // - Else, change current char to ')'
            ch = ')';
        }
    }

    return inputCopy;
}

int main()
{
    

    return 0;
}
