#include <iostream>     // for std::cout

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

int main()
{
    std::cout << "Hello there, world!\n";
    return 0;
}
