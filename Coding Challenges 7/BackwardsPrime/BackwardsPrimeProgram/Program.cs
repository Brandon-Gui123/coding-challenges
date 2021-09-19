using System;
using System.Collections.Generic;
using System.Linq;

namespace BackwardsPrimeProgram
{
    class Program
    {
        static void Main(string[] args)
        {
            ShowOutputAsExampleFormat(2, 100);
        }

        static List<int> GetEmirpsFromRange(int start, int end)
        {
            List<int> emirps = new();

            foreach (int value in Enumerable.Range(start, end))
            {
                if (BackwardsPrimeMethods.IsEmirp(value))
                {
                    emirps.Add(value);
                }
            }

            return emirps;
        }
    
        static void ShowOutputAsExampleFormat(int start, int end)
        {
            List<int> emirps = GetEmirpsFromRange(start, end);

            Console.WriteLine($"backwardsPrime({start}, {end}) =>");

            Console.Write('[');
            for (int i = 0; i < emirps.Count; i++)
            {
                Console.Write(emirps[i]);

                if (i != emirps.Count - 1)
                {
                    // add a comma and a space
                    // for elements that aren't last
                    Console.Write(", ");
                }
            }
            Console.WriteLine(']');
        }
    }
}