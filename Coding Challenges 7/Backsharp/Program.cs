using System;
using System.Text;

namespace Backsharp
{
    class Program
    {
        static void Main(string[] args)
        {
            PrintInChallengeFormat("abc#d##c");
            PrintInChallengeFormat("abc##d###");
        }

        public static string Backsharp(string input, char backspaceChar = '#')
        {
            StringBuilder modified = new();

            foreach (char inputCh in input)
            {
                if (inputCh == backspaceChar)
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
