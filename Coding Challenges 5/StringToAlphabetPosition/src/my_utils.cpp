#include <cctype>       // for std::isalpha
#include <string>       // for std::string

namespace my_utils
{
    std::string remove_non_alpha(const std::string& str)
    {
        std::string modifiedString{};

        for (char ch : str)
        {
            if (std::isalpha(ch))
            {
                modifiedString.push_back(ch);
            }
        }

        return modifiedString;
    }

    void to_lowercase(std::string& strToModify)
    {
        for (char& ch : strToModify)
        {
            ch = std::tolower(ch);
        } 
    }
}
