#include "string_number.h"

#include <string>

brandon_utils::string_number::string_number(int i) : num{ std::to_string(i) }
{}

bool brandon_utils::operator==(const string_number& lhs, const string_number& rhs)
{
    return lhs.num == rhs.num;
}

bool brandon_utils::operator!=(const string_number& lhs, const string_number& rhs)
{
    return lhs.num != rhs.num;
}

brandon_utils::string_number brandon_utils::operator+(const string_number& lhs, const string_number& rhs)
{
    string_number sum{ lhs };
    bool carry_over{ false };

    int sum_index{ static_cast<int>(sum.num.length() - 1) };

    for (int rhs_index{ static_cast<int>(rhs.num.length()) - 1 }; rhs_index >= 0; --sum_index, --rhs_index)
    {
        if (sum_index == -1)
        {
            // we need to add digits to the sum variable
            sum.num.insert(0, 1, '0');

            // so we can read the very first digit in the variable
            sum_index = 0;
        }

        int digit_sum{ (sum.num.at(sum_index) - '0') + (rhs.num.at(rhs_index) - '0') };

        if (carry_over)
        {
            digit_sum += 1;
        }

        if (digit_sum >= 10)
        {
            digit_sum = digit_sum % 10;
            carry_over = true;
        }
        else
        {
            carry_over = false;
        }

        sum.num.at(sum_index) = digit_sum + '0';
    }

    // any more carry overs?
    while (carry_over)
    {
        if (sum_index == -1)
        {
            // we need to add digits to the sum variable
            sum.num.insert(0, 1, '0');

            // so we can read the very first digit in the variable
            sum_index = 0;
        }

        int digit_sum{ (sum.num[sum_index] - '0') + 1 };

        if (digit_sum >= 10)
        {
            digit_sum = digit_sum % 10;
            carry_over = true;
        }
        else
        {
            carry_over = false;
        }

        sum.num.at(sum_index) = digit_sum + '0';
        --sum_index;
    }

    return sum;
}
