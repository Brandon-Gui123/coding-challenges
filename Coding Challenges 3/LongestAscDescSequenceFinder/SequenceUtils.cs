namespace LongestAscDescSequenceFinder
{
    using System.Collections.Generic;

    public class SequenceUtils
    {
        public static List<int> DeconstructToDigits(int number)
        {
            List<int> numberDigits = new();

            do
            {
                numberDigits.Insert(0, number % 10);
                number /= 10;
            }
            while (number > 0);

            return numberDigits;
        }
    }
}
