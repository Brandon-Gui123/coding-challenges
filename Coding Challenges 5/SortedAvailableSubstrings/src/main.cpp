#include <algorithm>    // for std::algorithm
#include <array>        // for std::array
#include <iostream>
#include <string>       // for std::string
#include <vector>       // for std::vector

int main()
{
    // inputs
    std::array<std::string, 3> substrInputs{ "strong", "live", "arp" };
    std::array<std::string, 5> strInputs{ "lively", "alive", "harp", "sharp", "armstrong" };
    
    // first, we have to find if a specific substring in 'substrInputs'
    // exists in any one of the strings in 'strInputs'
    // this can probably be done using 'std::string.find()'

    // create a vector to hold all the substrings that are
    // present in the given string inputs
    // we will push to this vector as we search
    std::vector<std::string> presentSubstrings{};

    // iterate through each substring
    for (const std::string& substr : substrInputs)
    {
        // and then iterate through each string
        for (const std::string& inputStr : strInputs)
        {
            // check if the substring exists in the
            // input string

            // if the result isn't 'std::string::npos'
            // it means we found something
            if (inputStr.find(substr) != std::string::npos)
            {
                // push the substring to the vector
                // since this one's valid
                presentSubstrings.push_back(substr);

                // no need to go through all other
                // strings since a match has already
                // been found
                break;
            }
        }
    }

    // sort the strings according to alphabetical order
    // which is lexicographic for alphabets
    std::sort(presentSubstrings.begin(), presentSubstrings.end());

    // print to show something
    std::cout << '[';
    for (const std::string& str : presentSubstrings)
    {
        if (str == *presentSubstrings.rbegin())
        {
            // print differently for last element
            std::cout << " \"" << str << "\" ]";
        }
        else
        {
            std::cout << " \"" << str << "\",";
        }
    }

    return 0;
}
