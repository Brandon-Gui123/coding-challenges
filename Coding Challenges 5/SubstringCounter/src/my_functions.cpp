#include <string>       // for std::string

namespace my_functions
{
    int getSubstringCount(const std::string& fullText, const std::string& substring)
    {
        int numMatches{ 0 };
        auto substringIterator{ substring.begin() };
        
        for (const char currentFullTextChar : fullText)
        {
            if (currentFullTextChar == *substringIterator)
            {
                // for checking if the next character also matches the full text char in
                // the next iteration
                ++substringIterator;

                if (substringIterator == substring.end())
                {
                    // reaching the end of the substring means a match
                    // has been successful
                    ++numMatches;
                }
            }
            else
            {
                substringIterator = substring.begin();
            }
        }

        return numMatches;
    }
}
