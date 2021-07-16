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
            Console.WriteLine("Hello World!");
        }
    }
}
