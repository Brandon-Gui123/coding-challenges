
#include <string>   // for std::string
#include <vector>   // for std::vector

int getDifferenceBetweenLongestAndShortest(const std::vector<std::string>& strings)
{
    // Fastest solution that I came up with:
    // 1. The array of strings is a vector.
    // 2. Keep track of longest and shortest lengths
    //    in 2 integer variables.
    // 3. The value in those 2 variables is the length
    //    of the first string in the vector.
    // 4. Iterate through all the strings in the vector.
    //    During the iteration,
    //    4.1. Compare current string's length to the
    //         2 integer variables declared.
    //    4.2. If length is more than max, that length is
    //         now the max.
    //    4.3. If length is less than min, that length is
    //         now the min.
    // 5. Subtract min from max (max - min).
    // 6. Return the result from (max - min).

    size_t shortestLength{ strings[0].length() };
    size_t longestLength{ strings[0].length() };

    for (const std::string& str : strings)
    {
        if (str.length() < shortestLength)
        {
            shortestLength = str.length();
        }

        if (str.length() > longestLength)
        {
            longestLength = str.length();
        }
    }

    return longestLength - shortestLength;
}
