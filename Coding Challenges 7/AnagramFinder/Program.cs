using System;
using System.Collections.Generic;
using System.Linq;

namespace AnagramFinder
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = "baba";

            Console.WriteLine($"anagrams(\"{input}\") =>");

            List<string> anagrams = Anagrams.Get(input);
            foreach (string anagram in anagrams)
            {
                if (anagram == anagrams.First())
                {
                    Console.Write('[');
                }

                Console.Write($"\"{anagram}\"");

                if (anagram == anagrams.Last())
                {
                    Console.Write(']');
                }
                else
                {
                    Console.Write(", ");
                }
            }
        }
    }
}
