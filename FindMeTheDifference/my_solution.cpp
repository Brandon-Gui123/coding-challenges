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

int getStringLength(const char* charPointer)
{
    // to count the length of the string, we can iterate
    // and count up each character in the string
    // until we hit the null terminator
    int length{ 0 };

    while (*charPointer != '\0')
    {
        ++length;
        ++charPointer;
    }

    return length;
}

int getDifferenceBetweenLongestAndShortest_CharPointer(const char** begin, const char** end)
{
    // to find the longest and shortest strings,
    // we need to iterate through each string element
    // we do it just like what we did above for the vector,
    // only this time we're dealing with pointers
    int shortestLength{ getStringLength(*begin) };
    int longestLength{ getStringLength(*begin) };   // -1 here because remember, end is the element after the last!

    for (const char** charPointer{ begin }; charPointer != end; ++charPointer)
    {
        int currentStringLength{ getStringLength(*charPointer) };

        if (currentStringLength > longestLength)
        {
            longestLength = currentStringLength;
        }

        if (currentStringLength < shortestLength)
        {
            shortestLength = currentStringLength;
        }
    }

    return longestLength - shortestLength;
}
