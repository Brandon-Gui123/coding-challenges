/*
 * I was curious how people do it and found one solution
 * here: https://www.geeksforgeeks.org/find-cubic-root-of-a-number/
 *
 * Basically, it uses binary search to find a number and check
 * if the cubed of the number is equal to the method argument.
 *
 * Here, I've re-written it with comments and a default argument
 * for the epsilon.
 */

namespace CubeRoot
{
    using System;

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine($"- 27 : {GetCubeRoot(27)}");
            Console.WriteLine($"- 729 : {GetCubeRoot(729)}");
            Console.WriteLine($"- 2 : {GetCubeRoot(2)}");
        }

        // One way is to brute force our way
        // using binary search.
        public static double GetCubeRoot(double num, double error = double.Epsilon)
        {
            // the cube root of num will typically give an
            // answer that is less than num
            double start = 0;
            double end = num;

            // intentional while loop so we keep going until we find a solution
            while (true)
            {
                // to perform a binary search, we start with a number in between the two
                double middle = (start + end) / 2;

                // with the middle number, we check if it is the cube root of num
                // to do that, we raise the middle number by 3 and compare equality
                // with num (we'll need an epsilon here)
                double middleCubed = middle * middle * middle;
                if (Math.Abs(middleCubed - num) <= error)
                {
                    // yes? Then the middle number is our cube root
                    return middle;
                }
                else
                {
                    // no? Let's check our middleCubed number

                    // if our cubed value is higher than num,
                    // it means we have to go lower
                    if (middleCubed > num)
                    {
                        // so we adjust our end to be closer to 0
                        // to do that, we set end to our current middle value
                        end = middle;
                    }
                    else
                    {
                        // our cubed value is lower than num
                        // it means we have to go higher

                        // so we adjust our start to be closer to end
                        // to do that, we set start to our current middle value
                        start = middle;
                    }
                }
            }
        }

    }
}
