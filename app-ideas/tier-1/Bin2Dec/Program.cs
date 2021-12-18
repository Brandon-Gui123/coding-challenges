using System;

namespace Bin2Dec
{
    class Program
    {
        static void Main(string[] args)
        {
            string binaryInput = "11111111";

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
