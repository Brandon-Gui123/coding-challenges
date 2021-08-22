#include <vector>       // for std::vector

namespace my_functions
{
    char findMissingLetter(const std::vector<char>& consecutiveLetters)
    {
        // requirements: consecutive (increasing letters)
        // this means the vector is expected to have already been sorted

        // fastest solution I can think of: rely on the ASCII table

        // initialize a variable to hold the value of the first element in the vector
        char expectedLetter{ consecutiveLetters[0] };
        
        // create a 'for' loop, starting at vector's 2nd element, all the way to the end
        for (int i{ 1 }; i < consecutiveLetters.size(); ++i)
        {
            // increment the variable declared above by 1 (++)
            ++expectedLetter;
            
            // compare equality of variable and element at index i
            if (expectedLetter != consecutiveLetters[i])
            {
                // if different, return the expected letter
                return expectedLetter;
            }
        }
        
        // we need a sentinel to indicate that there are no missing letters
        // maybe we can return '0' for now (it isn't even a letter so we should be good)

        return '0';
    }
}