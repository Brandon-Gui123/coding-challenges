using System;
using System.Collections.Generic;
using System.Linq;

namespace AnagramFinder
{
    class Program
    {

        static void Increment(int[] indices, int limit)
        {
            indices[^1]--;

            for (int i = indices.Length - 1; i >= 1; i--)
            {
                if (indices[i] == -1)
                {
                    // carry over to next index
                    indices[i - 1]--;

                    // reset current
                    indices[i] = limit;
                }
            }
        }

        static void Main(string[] args)
        {
            List<int> input = new() { 0, 2, 2, 2 };

            // the number of indices to create
            // depends on how many inputs we have
            int[] indices = new int[input.Count];

            for (int i = 0; i < indices.Length; i++)
            {
                // make all indices point to the last element in the input list
                indices[i] = input.Count - 1;
            }

            // the first index in the indices list goes from last to first in the input list

            // after that index is at the first element in the list,
            // move the next index in the indices list up by 1

            List<string> permutations = new();

            while (true)
            {
                string permutation = "";

                // ignore permutation if 1 or more indices are equal to
                // another
                if (indices.Distinct().Count() == indices.Length)
                {
                    for (int i = 0; i < indices.Length; i++)
                    {
                        permutation += input[indices[i]];
                    }

                    if (!permutations.Contains(permutation))
                    {
                        permutations.Add(permutation);
                    }
                }

                // next index?????? idk
                Increment(indices, input.Count - 1);

                if (indices.Any(index => index < 0))
                {
                    Console.WriteLine("Terminate infinite loop");
                    break;
                }
            }

            foreach (string permutation in permutations)
            {
                Console.WriteLine(permutation);
            }
        }
    }
}
