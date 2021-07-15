namespace LongestAscDescSequenceFinder
{
    using System.Collections.Generic;

    public class SequenceUtils
    {
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
    }
}
