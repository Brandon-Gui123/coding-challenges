#ifndef MY_UTILS_H
#define MY_UTILS_H

#include <string>       // for std::string

namespace my_utils
{
    std::string remove_non_alpha(const std::string& str);

    void to_lowercase(std::string& str_to_modify);

    int get_letter_pos(char ch);
}

#endif // !MY_UTILS_H
