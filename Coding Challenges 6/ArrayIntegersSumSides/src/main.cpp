#include <cstddef>      // for std::size_t
#include <limits>       // for std::numeric_limits
#include <vector>
#include <iostream>

std::size_t leftRightSumIndexEquals(const std::vector<int>& integerVector)
{
    constexpr std::size_t noMatchValue{ std::numeric_limits<std::size_t>::max() };
    
    // we need at least 3 elements so we got a left, middle and right
    // else, finding the sum of left and right between middle 
    // will not make sense
    if (integerVector.size() < 3)
    {
        // I picked the max value of std::size_t as the return value for arrays
        // with insufficient length
        // or when no matches are found because the appropriate index values
        // will never be at that value (since there's no element after that!)
        // It is also slightly better than 0 since such a value is probably
        // unique
        return noMatchValue;
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

    return noMatchValue;
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
