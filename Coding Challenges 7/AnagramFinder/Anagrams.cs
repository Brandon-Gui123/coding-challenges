using System.Collections.Generic;
namespace AnagramFinder
{
    public static class Anagrams
    {
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