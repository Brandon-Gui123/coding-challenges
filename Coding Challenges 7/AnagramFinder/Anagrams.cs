using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AnagramFinder
{
    public static class Anagrams
    {
        public static List<string> Get(string word)
        {
            // cannot find anagrams if string is empty
            // or null
            if (string.IsNullOrEmpty(word))
            {
                return null;
            }
            
            List<int> indexers = new(word.Length);

            // makes all indexes point to the last
            // element in the word
            for (int i = 0; i < word.Length; i++)
            {
                indexers.Add(word.Length - 1);
            }

            // permutations are meant to be unique,
            // so use of a HashSet will greatly
            // benefit us when we use the Contains()
            // method since this gives us O(1)
            // time complexity
            HashSet<string> permutations = new();

            // for building a single permutation
            // that shall be added to the hash set
            StringBuilder permutationBuilder = new(word.Length);

            // continue iterating if all of the
            // indexes have valid index, meaning
            // their values are non-negative
            while (indexers.All(index => index >= 0 && index < word.Length))
            {
                // only build permutation if all of the indexes
                // are distinct
                if (indexers.Distinct().Count() == indexers.Count)
                {
                    foreach (int index in indexers)
                    {
                        permutationBuilder.Append(word[index]);
                    }

                    permutations.Add(permutationBuilder.ToString());

                    // for the next permutation to use
                    permutationBuilder.Clear();
                }

                // advance indexes
                // the point is to have the last indexer to point
                // to the previous character whilst the other indexers
                // don't move. This will continue until the last indexer
                // reaches the first character of the word.
                // Then, the second-last indexer will advance to the previous
                // character and the last indexer will go back to the last character.
                // This is then repeated for all the indexers all the way to the
                // first indexer.
                // This will allow us to get all the permutations.
                // You can think of this as counting numbers.
                // You go from 0 to 9, after which, you add a 1 to get 10,
                // then go from 0 to 9 in the ones place again (10 to 19).
                AdvanceIndexers(indexers, word.Length);
            }

            // the subject of the anagram (i.e. the word itself)
            // isn't supposed to be in the set so remove it
            permutations.Remove(word);

            return permutations.ToList();
        }

        private static void AdvanceIndexers(List<int> indexers, int wordCount)
        {
            // this moves the last index to point at the
            // element before what it is pointing
            indexers[^1]--;

            // to go through all other indexers, except the first one
            for (int i = indexers.Count - 1; i >= 1; i--)
            {
                if (indexers[i] == -1)
                {
                    indexers[i - 1]--;
                    indexers[i] = wordCount - 1;
                }
            }
        }
    }
}