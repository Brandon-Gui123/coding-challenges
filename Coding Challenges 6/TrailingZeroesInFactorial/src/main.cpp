#include <iostream>

int getNumberOfTrailingZeroesInFactorialOf(int factorialOf)
{
    /*
     * In 5!, the expression expands to 5 * 4 * 3 * 2 * 1.
     * 5 * 4 gives 20 and since multiplication is associative,
     * 20 * 3 * 2 * 1 is the same as 5 * 4 * 3 * 2 * 1.
     *
     * Since we have 20 as the product of 5 * 4, any number multiplied
     * with 20 will give a value where the digit in the ones place is 0.
     *
     * Now let's look at 9!, which expands to 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.
     * So far the only pairs that make a product ending with a 0 is
     * the even numbers, multiplied by 5 (i.e. 8 * 5, 6 * 5, 4 * 5, 2 * 5).
     * However, we only have one '5' available, so we can only make just one
     * number ending with 0. Hence, at 9!, we still have one trailing zero.
     *
     * For 10!, it expands to 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.
     * Since multiplication is associative, we can treat 10! as 10 * 9!.
     * Multiplying any non-zero number by 10 adds a '0' to the end, so
     * 10! will receive an extra trailing zero
     * (As an aside, notice the difference in the digits between 10! and 9!
     * is the extra zero on the right?).
     *
     * For 15! (and any number that ends with 5), it expands to 15 * 14... * 1,
     * which can be paired with an even number to form a number that ends with 0
     * (e.g. 15 * 14 will give you 210, which ends with 0).
     * For 15!, we have 2 pairs of numbers to give 0 (e.g. 15 * 14, 5 * 4), and
     * a 10 to give an extra 0. 15 * 14 and 5 * 4 evaluate to 210 and 20 respectively,
     * which means, when multiplied together, we get another 2 zeroes.
     * In total, we get 3 trailing zeroes (10 * 210 * 20).
     *
     * For 20!, we have the trailing zeroes from 15!, plus one from 20, which
     * is (10 * 2).
     *
     * Looking at this pattern, it appears an extra trailing zero appears at every
     * 5th value. This means the number of trailing zeroes we have is equal to the
     * quotient of n / 5 (integer division, so decimals are truncated),
     * where n is the value in n!.
     */
    return factorialOf / 5;
}

int main()
{
    std::cout << "Hello there, world!\n";
    return 0;
}
