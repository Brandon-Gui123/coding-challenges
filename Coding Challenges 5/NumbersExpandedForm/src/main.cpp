#include "my_constants.h"
#include "my_functions.h"

#include <iostream>
#include <string>       // for std::string
#include <vector>       // for std::vector

int main()
{
    // plan
    // input: double
    // output: string

    // not a good idea to simply subtract sampleInput with the integral
    // part to get the decimal parts because floating point errors
    // may cause a ton of decimals to show up
    // so to prevent floating point errors, we should convert the input to a string

    double sampleInput{ 101.24 };

    std::string sampleInputAsString{ std::to_string(sampleInput) };

    // to separate the integral and decimal parts, we can loop through all the characters
    // in the string and first store it in a vector for integral digits
    // when we encounter a period (the decimal dot), we can set a boolean and this time,
    // all the numbers we encounter in the loop are going to another vector for decimal digits
    std::vector<char> integralDigits{};
    std::vector<char> decimalDigits{};

    bool shouldFillDecimalDigits{ false };
    for (char digit : sampleInputAsString)
    {
        if (digit == my_constants::dotChar)
        {
            shouldFillDecimalDigits = true;

            // to skip the decimal dot
            continue;
        }

        if (shouldFillDecimalDigits)
        {
            decimalDigits.push_back(digit);
        }
        else
        {
            integralDigits.push_back(digit);
        }
    }

    // the leftmost digit of the input is the first element in the integralDigits vector
    // and also, this digit has the highest place value.
    // to easily deal with this, we can use 'rbegin()' and 'rend()' to instead start
    // from the last element, which is the digit with the lowest place value
    // then as we iterate, we add a '0' to the end of the "10"
    std::string multiplyValue{ my_constants::tenString };
    std::vector<std::string> expandedForms{};
    for (auto intCharIt{ integralDigits.rbegin() }; intCharIt != integralDigits.rend(); ++intCharIt)
    {
        // treat the first element differently
        // because for this element, we don't need to add "* 10"
        if (intCharIt == integralDigits.rbegin())
        {
            // zeroes are not to be included in the expanded form
            if (*intCharIt != my_constants::zeroChar)
            {
                expandedForms.push_back(std::string{ 1, *intCharIt });
            }

            // to keep the number of indentations low
            // compared to using an 'else'
            continue;
        }

        // zeroes are not to be included in the expanded form
        if (*intCharIt != my_constants::zeroChar)
        {
            // expanded form consists of the digit, a multiplication symbol, a multiplier value and whitespaces
            std::string expandedForm{ 1, *intCharIt };
            expandedForm += ' ';
            expandedForm += my_constants::multiplyChar;
            expandedForm += ' ';
            expandedForm += multiplyValue;

            // insert at the beginning of the vector so printing vector contents becomes easier
            expandedForms.insert(expandedForms.begin(), expandedForm);
        }

        // for the next digit
        multiplyValue += my_constants::zeroChar;
    }

    // for decimal digits, the process is the same as above
    // but we can start at the first element instead of the last
    // since the first element's place value is the highest among
    // the other decimal digits (we start with n / 10, then n / 100 etc.)
    std::string divideValue{ my_constants::tenString };
    for (auto decCharIt{ decimalDigits.begin() }; decCharIt != decimalDigits.end(); ++decCharIt)
    {
        // zeroes not to be included
        if (*decCharIt != my_constants::zeroChar)
        {
            // expanded form consists of the digit, a division symbol, the divisor and whitespaces
            std::string expandedForm{ 1, *decCharIt };
            expandedForm += ' ';
            expandedForm += my_constants::divideChar;
            expandedForm += ' ';
            expandedForm += divideValue;

            expandedForms.push_back(expandedForm);
        }

        // for the next digit
        divideValue += my_constants::zeroChar;
    }

    std::cout << "Expanded forms:\n";
    my_functions::printVectorToStdOut(expandedForms);
    std::cout << '\n';

    // now we need to concatenate all of them and
    // add in '+' as necessary
    std::string fullExpandedForm{};
    for (const auto& str : expandedForms)
    {
        // do not add '+' if the element is last
        if (str == *expandedForms.rbegin())
        {
            fullExpandedForm += str;
        }
        else
        {
            fullExpandedForm += str;
            fullExpandedForm += ' ';
            fullExpandedForm += my_constants::plusChar;
            fullExpandedForm += ' ';
        }
    }

    std::cout << sampleInput << '\n';
    std::cout << fullExpandedForm << '\n';
    
    return 0;
}
