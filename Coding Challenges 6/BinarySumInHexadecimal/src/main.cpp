#include <iostream>     // for std::cout
#include <vector>       // for std::vector

struct SumBooleansResult
{
public:
    bool resultingValue{};
    bool carryOver{};
};

SumBooleansResult sumBooleans(bool first, bool second)
{
    if (first ^ second)
    {
        // both booleans are different in value
        // the summation will result in a '1' or a true
        return { true, false };
    }
    else if (first && second)
    {
        // both booleans are the same in value
        // the resulting value will be a '0' but
        // whether there is carry over will depend on what the individual
        // values were
        // if the individual values were '1' (true), then there's carry over
        // else, no carry over
        return { false, first };
    }
}

// Takes two vectors and adds zeroes to the shorter vector until
// the size is equal to the other.
void makeEqualSize(std::vector<bool>& first, std::vector<bool>& second)
{
    if (first.size() == second.size())
    {
        // no need to do anything
        return;
    }
    else
    {
        if (first.size() < second.size())
        {
            first.insert(first.begin(), second.size() - first.size(), false);
        }
        else
        {
            second.insert(second.begin(), first.size() - second.size(), false);
        }
    }
}

std::vector<bool> sum(const std::vector<bool>& first, const std::vector<bool>& second)
{
    // we may need to modify both Boolean vectors, so let's make a copy
    std::vector<bool> firstCopy{ first };
    std::vector<bool> secondCopy{ second };

    // ensure both vectors are of equal size
    // this will simplify addition
    makeEqualSize(firstCopy, secondCopy);

    // for when the previous summation of Booleans resulted in a value to carry over
    bool hasCarryOver{ false };
    
    for (auto firstCopyIt{ firstCopy.rbegin() }, secondCopyIt{ secondCopy.rbegin() };
        firstCopyIt != firstCopy.rend() && secondCopyIt != secondCopy.rend();
        ++firstCopyIt, ++secondCopyIt)
    {
        // sum the 2 Booleans that both iterators are pointing to
        SumBooleansResult sumResult{ sumBooleans(*firstCopyIt, *secondCopyIt) };

        // we will use the first Boolean vector to return the result
        // so we modify that
        *firstCopyIt = sumResult.resultingValue;

        // any carry over required from summing both Booleans?
        bool currentHasCarryOver{ sumResult.carryOver };

        // for possible carry over due to summing a Boolean with a carry over
        bool carryOverHasCarryOver{ false };

        // if there's carry over from the previous sum, we will need to apply it here
        if (hasCarryOver)
        {
            // sum the current Boolean with the carry over
            SumBooleansResult carryOverSumResult{ sumBooleans(*firstCopyIt, true) };
            *firstCopyIt = carryOverSumResult.resultingValue;
            
            // any carry over required from summing with a carry over?
            carryOverHasCarryOver = carryOverSumResult.carryOver;
        }

        // we won't have times when we have 2 carry overs so we
        // can use the XOR operator here to specify if a carry over
        // is required for the next digit
        hasCarryOver = currentHasCarryOver ^ carryOverHasCarryOver;
    }

    // do we still have carry over?
    // if we have, we need to add a 1 to the first copy vector
    if (hasCarryOver)
    {
        firstCopy.insert(firstCopy.begin(), true);
    }

    return firstCopy;
}

int main()
{
    std::cout << "Hello there, world!\n";
    return 0;
}
