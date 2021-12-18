using System;

namespace Bin2Dec
{
    class Program
    {
        static void Main(string[] args)
        {
            // assume input is from the first argument
            string binaryInput = args[0];

            // check that input contains ONLY 0's and 1's
            foreach (char chInput in binaryInput)
            {
                if (chInput != '0' && chInput != '1')
                {
                    Console.WriteLine("Input can only contain 0's and 1's");
                    return;
                }
            }

            var sum = 0;

            for (int i = binaryInput.Length - 1; i >= 0; i--)
            {
                var digit = (int)char.GetNumericValue(binaryInput[i]);

                if (digit == 1)
                {
                    sum += (int)Math.Pow(2, binaryInput.Length - 1 - i);
                }
            }

            Console.WriteLine(sum);
        }
    }
}
