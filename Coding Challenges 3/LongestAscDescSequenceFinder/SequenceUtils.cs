namespace LongestAscDescSequenceFinder
{
    using System.Collections.Generic;

    public class SequenceUtils
    {
        public static List<int> DeconstructToDigits(int number)
        {
            List<int> numberDigits = new();

            for (int num = number; num > 0; num /= 10)
            {
                numberDigits.Insert(0, num % 10);
            }

            return numberDigits;
        }
    }
}
