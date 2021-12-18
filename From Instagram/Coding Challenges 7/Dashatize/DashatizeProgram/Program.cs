using System;
using System.Collections.Generic;
using System.Text;

namespace DashatizeUtils
{
    class Program
    {
        static void Main(string[] args)
        {
            int input1 = 274;
            string dashatized1 = Dashatize.DashatizeOdds(input1);
            Console.WriteLine($"dashatize({input1}) => '{dashatized1}'");

            int input2 = 6814;
            string dashatized2 = Dashatize.DashatizeOdds(input2);
            Console.WriteLine($"dashatize({input2}) => '{dashatized2}'");
        }
    }
}
