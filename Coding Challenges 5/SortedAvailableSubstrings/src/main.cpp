#include <algorithm>    // for std::algorithm
#include <array>        // for std::array
#include <iostream>
#include <string>       // for std::string
#include <vector>       // for std::vector

int main()
{
    // create a vector to hold substrings given by the user
    std::vector<std::string> userSubstrInputs{};
    
    // infinite loop
    while (true)
    {
        // ask the user for a string
        std::cout << "Enter a substring (input nothing to end): ";
        std::string strInput;

        // allows reading empty strings, which means the user can
        // simply hit "Enter" w/o giving input and we can read that
        // to end the input
        std::getline(std::cin, strInput, '\n');
        
        // if the string is empty, exit out of the loop
        if (strInput == "")
        {
            std::cout << "End.\n";
            break;
        }
        
        // check if the string exists
        if (std::find(userSubstrInputs.begin(), userSubstrInputs.end(), strInput) != userSubstrInputs.end())
        {
            // if the string exists, deny input and let the user try again
            std::cout << '"' << strInput << "\" already added! Try again.\n";   
        }
        else
        {
            // else, add the string to the vector and inform the user
            userSubstrInputs.push_back(strInput);
            std::cout << "Added \"" << strInput << "\"\n";
        }
    }

    // create another vector to hold strings given by the user
    std::vector<std::string> userStringInputs{};

    while (true)
    {
        std::cout << "Enter a string (input nothing to end): ";
        std::string strInput;
        std::getline(std::cin, strInput, '\n');

        if (strInput == "")
        {
            std::cout << "End.\n";
            break;
        }
        else
        {
            if (std::find(userStringInputs.begin(), userStringInputs.end(), strInput) != userStringInputs.end())
            {
                std::cout << '"' << strInput << "\" already added! Try again.\n";
            }
            else
            {
                userStringInputs.push_back(strInput);
                std::cout << "Added \"" << strInput << "\"\n";
            }
        }
    }

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
