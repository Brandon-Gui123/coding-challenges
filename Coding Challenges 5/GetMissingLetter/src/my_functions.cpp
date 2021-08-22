#include <vector>       // for std::vector

namespace my_functions
{
    char findMissingLetter(const std::vector<char>& consecutiveLetters)
    {
        // requirements: consecutive (increasing letters)
        // this means the vector is expected to have already been sorted

        // a size of at least 2 is required so that the 'for' loop
        // below will have a second element to access
        if (consecutiveLetters.size() < 2)
        {
            return '0';
        }

        // fastest solution I can think of: rely on the ASCII table

        // initialize a variable to hold the value of the first element in the vector
        char expectedLetter{ consecutiveLetters[0] };
        
        // create a 'for' loop, starting at vector's 2nd element, all the way to the end
        // this is because there's no point comparing first element with our variable above,
        // which is also the value of the first element. The equality will always be true.
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