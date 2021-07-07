#include "string_number.h"

#include <string>               // for std::to_string
#include <vector>               // for std::vector

namespace brandon_utils
{
    string_number::string_number(int integer)
    {
        is_positive = integer >= 0;
        digits = {};

        do
        {
            // a char is a byte and we technically can store numbers as is.
            // only thing to take note is that when sent to standard out,
            // it displays a character and not an integer
            digits.insert(digits.begin(), integer % 10);
            integer /= 10;
        }
        while (integer != 0);
    }

    string_number string_number::add(const string_number& positive_left, const string_number& positive_right)
    {
        string_number result{ positive_left };

        auto result_rev_it{ result.digits.rbegin() };
        auto right_rev_it{ positive_right.digits.rbegin() };

        bool must_carry{ false };
        while (result_rev_it != result.digits.rend() && right_rev_it != positive_right.digits.rend())
        {
            *result_rev_it += *right_rev_it + (must_carry ? 1 : 0);

            if (*result_rev_it >= 10)
            {
                must_carry = true;
                *result_rev_it %= 10;
            }
            else
            {
                must_carry = false;
            }

            ++result_rev_it;
            ++right_rev_it;
        }

        // if the Boolean variable is true here, it means
        // a new digit must be added to the beginning
        if (must_carry)
        {
            result.digits.insert(result.digits.begin(), 1);
        }

        return result;
    }

    string_number operator+(const string_number& left, const string_number& right)
    {
        return string_number::add(left, right);
    }
}
