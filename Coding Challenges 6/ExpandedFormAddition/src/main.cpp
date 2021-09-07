#include <iostream>     // for std::cout
#include <string>       // for std::string
#include <vector>       // for std::vector

std::string expandInteger(int input)
{
    // 1. Initialize a vector. This vector will store the value of each digit in the input.
    //    (i.e. 123 will be stored as 3, 20 and 100. And it is backwards since I am starting
    //    the digit extraction from the right of the number)
    std::vector<int> digitValues{};

    // 2. Create a copy of the input. We'll use a do-while loop. (do-while so we can process at least once,
    //    even if our input is 0).
    //    Loop forever until the copy of the input is 0.
    //    To get the number of zeroes correct, we can use a multiplier that multiplies itself by 10 after
    //    every iteration. This multiplier is multiplied with the digit to get the value we need
    //    (e.g. 6 * 100 = 600).
    int inputCopy{ input };
    int multiplier{ 1 };
    do
    {
        int digit{ inputCopy % 10 };
        digitValues.push_back(digit * multiplier);

        inputCopy /= 10;
        multiplier *= 10;
    } while (inputCopy != 0);


    // 3. The highest-valued digit is on the right of the vector (i.e. last element).
    //    But we need to show the highest one first so we get 100 + 20 + 3 and not 3 + 20 + 100.
    //    To do this, we have to make use of a reverse iterator (which we can get via rbegin() and rend()).
    //    With that, we just need to build a string, adding spaces and pluses after each element,
    //    unless the element is the first, where we don't need to add spaces and pluses.
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
