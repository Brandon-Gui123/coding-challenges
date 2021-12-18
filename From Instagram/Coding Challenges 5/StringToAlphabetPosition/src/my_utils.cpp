#include <cctype>       // for std::isalpha
#include <string>       // for std::string

namespace my_utils
{
    std::string remove_non_alpha(const std::string& str)
    {
        std::string modified_string{};

        for (char ch : str)
        {
            if (std::isalpha(ch))
            {
                modified_string.push_back(ch);
            }
        }

        return modified_string;
    }

    void to_lowercase(std::string& str_to_modify)
    {
        for (char& ch : str_to_modify)
        {
            ch = std::tolower(ch);
        } 
    }

    int get_letter_pos(char ch)
    {
        return ch - '`';
    }
}
