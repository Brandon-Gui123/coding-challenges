#ifndef STRING_NUMBER_H
#define STRING_NUMBER_H

#include <string>           // for std::string

namespace brandon_utils
{
    class string_number
    {
    public:
        std::string num;

    public:
        string_number(int i);
    };

    bool operator==(const string_number& lhs, const string_number& rhs);
    bool operator!=(const string_number& lhs, const string_number& rhs);

    string_number operator+(const string_number& lhs, const string_number& rhs);
}

#endif // !STRING_NUMBER_H
