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
            string input = "baba";

            // the number of indices to create
            // depends on how many inputs we have
            int[] indices = new int[input.Length];

            for (int i = 0; i < indices.Length; i++)
            {
                // make all indices point to the last element in the input list
                indices[i] = input.Length - 1;
            }

            // the first index in the indices list goes from last to first in the input list

            // after that index is at the first element in the list,
            // move the next index in the indices list up by 1

            // since permutations are meant to be unique, we could
            // use a HashSet here.
            // This will gives us O(1) time complexity when using the
            // Contains() method
            HashSet<string> permutations = new();

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

                    // the Add() method will not add the permutation
                    // if it already exists, so we don't have to check
                    // beforehand since it already does the checking for us
                    permutations.Add(permutation);
                }

                // next index?????? idk
                Increment(indices, input.Length - 1);

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
