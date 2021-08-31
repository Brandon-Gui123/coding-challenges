#include <vector>
#include <iostream>

int leftRightSumIndexEquals(const std::vector<int>& integerVector)
{
    int leftSum{ integerVector[0] };
    int rightSum{ 0 };

    for (int i{ 2 }; i < integerVector.size(); ++i)
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
    for (int n{ 2 }; n < integerVector.size() - 1; ++n)
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
    std::cout << "Hello there, world!\n";
    return 0;
}
