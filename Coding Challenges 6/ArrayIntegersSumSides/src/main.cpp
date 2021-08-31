#include <cstddef>      // for std::size_t
#include <vector>
#include <iostream>

int leftRightSumIndexEquals(const std::vector<int>& integerVector)
{
    // we need at least 3 elements so we got a left, middle and right
    // else, finding the sum of left and right between middle 
    // will not make sense
    if (integerVector.size() < 3)
    {
        return -1;
    }
    
    int leftSum{ integerVector[0] };
    int rightSum{ 0 };

    for (std::size_t i{ 2 }; i < integerVector.size(); ++i)
    {
        rightSum += integerVector[i];
    }

    // sum of elements before the third element and
    // the sum of elements after the third element are equal
    if (leftSum == rightSum)
    {
        return 1;
    }

    // start at the third element because we've
    // already calculated the sum of the left and right
    // elements of the second element
    for (std::size_t n{ 2 }; n < integerVector.size() - 1; ++n)
    {
        leftSum += integerVector[n - 1];
        rightSum -= integerVector[n + 1];

        if (leftSum == rightSum)
        {
            return n;
        }
    }

    // this value will most likely not be used in array indexes
    // so we'll use this return value to indicate that we can't
    // find anything
    return -1;
}

int main()
{
    std::vector integerVector{ 1, 2, 3, 4, 3, 2, 1 };
    std::cout << leftRightSumIndexEquals(integerVector) << '\n';

    std::vector anotherOne{ 1, 100, 50, -51, 1, 1 };
    std::cout << leftRightSumIndexEquals(anotherOne) << '\n';

    std::vector myOwnVector{ 100, 100, 100, 100, 100 };
    std::cout << leftRightSumIndexEquals(myOwnVector) << '\n';

    std::vector noMatch{ 1, 2, 3, 4, 5 };
    std::cout << leftRightSumIndexEquals(noMatch) << '\n';

    return 0;
}
