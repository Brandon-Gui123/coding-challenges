#include <cmath>    // for std::sqrt and std::pow

int get_next_perfect_square(int square_number)
{
    // A perfect square is an integer that is the square of an integer.
    // So now we know we're dealing with just integers.

    // check if the argument provided is indeed a square number
    // a number is a square number if we get an integer from it
    //
    // we can check by rounding up the result using a ceiling function
    // if the value changes, it means that number is not an integer!
    // to check for value changes, check if the rounded number is more
    // than the original
    //
    // return -1 if not

    // else, perform a square root
    // add 1 to the result
    // then square and return the result

    const double num{ std::sqrt(square_number) };
    const double rounded{ std::ceil(num) };

    if (rounded > num)
    {
        // the number is not a square number
        return -1;
    }
    else
    {
        // get the next square number
        const int nextNum{ static_cast<int>(num) + 1 };
        const int result{ static_cast<int>(std::pow(nextNum, 2)) };
        return result;
    }

    return 0;
}
