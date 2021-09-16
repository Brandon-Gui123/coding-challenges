using System;

namespace NumberExpandedForm
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        private static void PrintLikeExample(int input)
        {
            Console.WriteLine($"expander({input}) -> '{NumberExpander.Expand(input)}'");
        }
    }
}
