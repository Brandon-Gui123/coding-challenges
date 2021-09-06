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
        int numOccurrences{ charactersTable[ch] };

        if (numOccurrences == 1)
        {
            ch = '(';
        }
        else
        {
            ch = ')';
        }
    }

    return inputCopy;
}

int main()
{
    std::cout << "din\t=>\t" << replaceOnceTwice("din") << '\n';
    std::cout << "recede\t=>\t" << replaceOnceTwice("recede") << '\n';

    return 0;
}
