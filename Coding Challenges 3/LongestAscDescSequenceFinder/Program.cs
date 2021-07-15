namespace LongestAscDescSequenceFinder
{
    using System;
    using System.Collections.Generic;

    class Program
    {
        static void Main(string[] args)
        {
            Sequence longestAscending = SequenceUtils.GetLongestAscendingSequenceFromNumber(74682);

            Console.Write("ASC- input: 74682\toutput: ");
            longestAscending.digits.ForEach(digit => Console.Write(digit));     // because why not? :P
            Console.WriteLine();
        }
    }
}
