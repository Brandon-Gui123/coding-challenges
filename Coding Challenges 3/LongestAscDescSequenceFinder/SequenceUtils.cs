namespace LongestAscDescSequenceFinder
{
    using System.Collections.Generic;

    public class SequenceUtils
    {
        /// <summary>
        /// Determines if <paramref name="current"/>, when compared to <paramref name="previous"/>,
        /// should be part of an ongoing sequence, or be the first element in a new sequence.
        /// </summary>
        /// <param name="current">The current element that we're interested in.</param>
        /// <param name="previous">The element before the current.</param>
        /// <returns>
        ///     <see langword="true"/> if <paramref name="current"/> shall become part of an ongoing sequence and
        ///     <see langword="false"/> if <paramref name="current"/> will be the first element in a new sequence.
        /// </returns>
        public delegate bool SequencePredicate(int current, int previous);

        public static List<Sequence> GetSequencesFromNumber(int number, SequencePredicate predicate)
        {
            // break our number down into an array of digits
            List<int> numberDigits = DeconstructToDigits(number);

            // to hold our sequences
            List<Sequence> sequences = new();

            Sequence currentSequence = new();                   // to hold the current sequence
            currentSequence.digits.Add(numberDigits[0]);  // store first digit for comparison with others

            // iterate through the array to find sequences that match our predicate
            for (int i = 1; i < numberDigits.Count; i++)
            {
                // is our predicate fulfilled?
                // by doing ^1, we are able to obtain the last element in the List
                // via a concise syntax
                if (predicate(numberDigits[i], currentSequence.digits[^1]))
                {
                    // store the digit in the sequence
                    currentSequence.digits.Add(numberDigits[i]);
                }
                else
                {
                    // this is where the sequence ends
                    // add the sequence to the List of sequences
                    sequences.Add(currentSequence);

                    // we start a new sequence for the number we're at right now
                    currentSequence = new();
                    currentSequence.digits.Add(numberDigits[i]);
                }
            }

            // add sequence to the list, if there are digits inside
            if (currentSequence.digits.Count > 0)
            {
                sequences.Add(currentSequence);
            }

            return sequences;
        }

        public static List<Sequence> GetAscendingSequencesFromNumber(int number)
        {
            // For ascending:
            // Find all ascending sequences in the number
            //  Break the number up into an array of digits
            //  Iterate through the array to find ascending sequences
            //      Construct a new array (this array holds a sequence of ascending digits)
            //      Store the first digit in the array for comparison with others
            //      Is the current digit greater than or equal to the last one in the array?
            //          Yes, store the digit in the array and repeat
            //
            //          No, our sequence ends at the last digit
            //              With all the digits in the array, we string all of them up and get a sequence.
            //      Repeat until we reach the end of the array

            // break our number down into an array of digits
            List<int> numberDigits = DeconstructToDigits(number);

            // to hold our sequences
            List<Sequence> sequences = new();

            Sequence currentSequence = new();                   // to hold the current sequence
            currentSequence.digits.Add(numberDigits[0]);  // store first digit for comparison with others

            // iterate through the array to find ascending sequences (exclude first digit)
            for (int i = 1; i < numberDigits.Count; i++)
            {
                // is the current digit greater than or equal to the last one in the array?
                // by doing ^1, we are able to obtain the last element in the List
                // via a concise syntax
                if (numberDigits[i] >= currentSequence.digits[^1])
                {
                    // store the digit in the sequence
                    currentSequence.digits.Add(numberDigits[i]);
                }
                else
                {
                    // this is where the sequence ends
                    // add the sequence to the List of sequences
                    sequences.Add(currentSequence);

                    // we start a new sequence for the number we're at right now
                    currentSequence = new();
                    currentSequence.digits.Add(numberDigits[i]);
                }
            }

            // add sequence to the list, if there are digits inside
            if (currentSequence.digits.Count > 0)
            {
                sequences.Add(currentSequence);
            }

            return sequences;
        }

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

        public static Sequence GetLongestSequenceFromNumber(int number, SequencePredicate sequencePredicate)
        {
            List<Sequence> sequences = GetSequencesFromNumber(number, sequencePredicate);

            int indexOfLongest = 0;

            for (int i = 0; i < sequences.Count; i++)
            {
                if (sequences[i].digits.Count > sequences[indexOfLongest].digits.Count)
                {
                    indexOfLongest = i;
                }
            }

            return sequences[indexOfLongest];
        }

        public static Sequence GetLongestAscendingSequenceFromNumber(int number)
        {
            List<Sequence> ascendingSequences = GetAscendingSequencesFromNumber(number);

            int indexOfLongest = 0;

            for (int i = 0; i < ascendingSequences.Count; i++)
            {
                if (ascendingSequences[i].digits.Count > ascendingSequences[indexOfLongest].digits.Count)
                {
                    indexOfLongest = i;
                }
            }

            return ascendingSequences[indexOfLongest];
        }
    }
}
