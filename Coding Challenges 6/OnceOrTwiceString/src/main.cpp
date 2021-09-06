#include <iostream>
#include <string>               // for std::string
#include <unordered_map>        // for std::unordered_map

int main()
{
    // Solution that came to my mind in the shortest amount of time:

    std::string inputString{ "recede" };
    
    // 1. Use an unordered map, storing char as a key and int as the value
    //    - key represents the char in the string
    //    - int represents the number of times char appeared in the string
    std::unordered_map<char, int> charactersTable{};

    // 2. Iterate through each character in a string
    for (const char ch : inputString)
    {
        // 3. Check if that char exists in the map
        if (charactersTable.contains(ch))
        {
            // - If it exists, access the value via the char and increment the value by 1
            charactersTable[ch] += 1;
        }
        else
        {
            // - If not, add a new key-value pair to the map, where key = char, value = 1
            charactersTable[ch] = 1;
        }
    }

    // 4. Go through each character in the string again. This time, we want to modify
    //    the characters.
    for (char& ch : inputString)
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

    std::cout << inputString << '\n';
    
    return 0;
}
