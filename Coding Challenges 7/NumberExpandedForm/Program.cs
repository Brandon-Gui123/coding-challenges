using System;

namespace NumberExpandedForm
{
    class Program
    {
        static void Main(string[] args)
        {
            PrintLikeExample(12);
            PrintLikeExample(6304);
        }

        private static void PrintLikeExample(int input)
        {
            Console.WriteLine($"expander({input}) -> '{NumberExpander.Expand(input)}'");
        }
    }
}
