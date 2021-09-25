using System;
using System.Text;

namespace Backsharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }

        public static string Backsharp(string input)
        {
            StringBuilder modified = new();

            foreach (char inputCh in input)
            {
                if (inputCh == '#')
                {
                    if (modified.Length >= 1)
                    {
                        modified.Remove(modified.Length - 1, 1);
                    }
                }
                else
                {
                    modified.Append(inputCh);
                }
            }

            return modified.ToString();
        }
    
        public static void PrintInChallengeFormat(string input)
        {
            Console.WriteLine($"backsharp(\"{input}\") -> \"{Backsharp(input)}\"");
        }
    }
}
