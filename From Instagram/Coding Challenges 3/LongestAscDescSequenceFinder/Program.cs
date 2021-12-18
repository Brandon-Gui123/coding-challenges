namespace LongestAscDescSequenceFinder
{
    using System;
    using System.Collections.Generic;

    class Program
    {
        static void Main(string[] args)
        {
            Sequence longestAscending = SequenceUtils.GetLongestSequenceFromNumber(74682, (current, previous) => current >= previous);
            Sequence longestDescending = SequenceUtils.GetLongestSequenceFromNumber(48642, (current, previous) => current <= previous);

            Console.Write("ASC- input: 74682\toutput: ");
            longestAscending.digits.ForEach(digit => Console.Write(digit));     // because why not? :P
            Console.WriteLine();

            Console.Write("DESC- input: 48642\toutput: ");
            longestDescending.digits.ForEach(digit => Console.Write(digit));
            Console.WriteLine();
        }
    }
}
