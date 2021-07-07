#ifndef STRING_NUMBER_H
#define STRING_NUMBER_H

#include <vector>               // for std::vector

namespace brandon_utils
{
    class string_number
    {
    private:
        std::vector<char> digits;
        bool is_positive;

    public:
        string_number(int integer);

    private:
        static string_number add(const string_number& positive_left, const string_number& positive_right);

    public:
        friend string_number operator+(const string_number& left, const string_number& right);
    };
}

#endif
