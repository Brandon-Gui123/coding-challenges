using System;
using System.Collections.Generic;

namespace BackwardsPrimeProgram
{
    public static class BackwardsPrimeMethods
    {
        public static bool IsPrime(int number)
        {
            // numbers lesser than 2 aren't valid prime numbers
            if (number < 2)
            {
                return false;
            }

            // trial division used here

            for (int i = 2; i < number; i++)
            {
                if (number % i == 0)
                {
                    return false;
                }
            }

            return true;
        }
    
        public static int ReverseNumber(int number)
        {
            bool isNegative = number < 0;
            int numberAsPositive = Math.Abs(number);

            List<int> digits = new();
            while (numberAsPositive != 0)
            {
                digits.Add(numberAsPositive % 10);
                numberAsPositive /= 10;
            }

            int result = 0;
            int multiplier = 1;
            for (int i = digits.Count - 1; i >= 0; i--)
            {
                result += digits[i] * multiplier;
                multiplier *= 10;
            }

            return isNegative ? result * -1 : result;
        }

        /// <summary>
        /// Checks if the given number is an emirp (which is a prime number, when read backwards,
        /// is also a prime number).
        /// </summary>
        /// <param name="number"></param>
        /// <returns></returns>
        /// <seealso href="https://en.wikipedia.org/wiki/Emirp">Emirp</seealso>
        public static bool IsEmirp(int number)
        {
            if (number >= 0 && number <= 9)
            {
                // single digits not allowed
                return false;
            }

            if (IsPrime(number))
            {
                int reversed = ReverseNumber(number);
                return reversed != number && IsPrime(reversed);
            }
            else
            {
                return false;
            }
        }
    }
}