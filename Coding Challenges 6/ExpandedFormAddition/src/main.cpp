#include <iostream>     // for std::cout
#include <string>       // for std::string
#include <vector>       // for std::vector

std::string expandInteger(int input)
{
    if (input == 0)
    {
        return "0";
    }

    std::vector<int> digitValues{};

    int inputCopy{ input };
    int multiplier{ 1 };
    do
    {
        int digit{ inputCopy % 10 };

        // ignore zeroes
        if (digit != 0)
        {
            digitValues.push_back(digit * multiplier);
        }

        inputCopy /= 10;
        multiplier *= 10;
    } while (inputCopy != 0);

    std::string expandedForm{};

    for (auto it{ digitValues.rbegin() }; it != digitValues.rend(); ++it)
    {
        expandedForm += std::to_string(*it);

        // is the iterator pointing to any element that's not the first?
        if (it != digitValues.rend() - 1)
        {
            expandedForm += " + ";
        }
    }

    return expandedForm;
}

int main()
{
    std::cout << 12 << "\t==>\t" << expandInteger(12) << '\n';
    std::cout << 421 << "\t==>\t" << expandInteger(421) << '\n';
    std::cout << 70304 << "\t==>\t" << expandInteger(70304) << '\n';

    return 0;
}
