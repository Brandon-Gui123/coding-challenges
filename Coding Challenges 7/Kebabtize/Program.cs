using System;
using System.Collections.Generic;
using System.Text;

namespace Kebabtize
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }

        public static string camelCaseToKebabCase(string input)
        {
            // indexes where we can find patterns where a lowercase
            // letter precedes an uppercase letter
            // the index is at the lowercase letter
            HashSet<int> foundSequencesIndexes = new();

            // detecting lowercase letters preceding uppercase letters
            for (int i = 0; i < input.Length - 1; i++)
            {
                char currentChar = input[i];
                char nextChar = input[i + 1];

                if (char.IsLower(currentChar) && char.IsUpper(nextChar))
                {
                    foundSequencesIndexes.Add(i);
                }
            }

            // kebabtizing the string

            // wastes less memory compared to using just strings
            StringBuilder kebabtizedStringBuilder = new();

            for (int i = 0; i < input.Length; i++)
            {
                if (foundSequencesIndexes.Contains(i))
                {
                    kebabtizedStringBuilder.Append(input[i])
                                           .Append('-')
                                           .Append(char.ToLower(input[i + 1]));

                    i++;
                }
                else
                {
                    kebabtizedStringBuilder.Append(input[i]);
                }
            }

            return kebabtizedStringBuilder.ToString();
        }
    }
}
