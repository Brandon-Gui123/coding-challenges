package LargestDigitNumber;

import java.util.ArrayList;

public class EntryPoint
{
    public static void main(String[] args)
    {
        System.out.println(getLargest5Sequence("1234567890"));
    }

    public static String getLargest5Sequence(String input)
    {
        ArrayList<IntSequence> sequences = new ArrayList<>();

        // we need at least one digit in the current sequence so we can
        // compare with other digits in the input
        IntSequence currentSequence = new IntSequence();

        // this uses the ASCII table to convert a char to an integer
        currentSequence.add(input.charAt(0) - '0');

        // i = 1 since the first digit is already in the sequence
        int currentSequenceIndex = 0;
        for (int i = 1; i < input.length(); i++)
        {
            int nextAsInt = input.charAt(i) - '0';

            // is the ones place of the current digit,
            // when added by 1, is equal to the next digit,
            // meaning they are consecutive (next comes after current)
            int previous = currentSequence.get(currentSequenceIndex);
            if ((previous + 1) % 10 == nextAsInt)
            {
                currentSequence.add(nextAsInt);
                currentSequenceIndex++;

                if (currentSequence.size() == 5)
                {
                    sequences.add(currentSequence);
                    currentSequence = new IntSequence();
                    // FIXME Last element in previous sequence gets carried over to next sequence as first element
                    if (i < input.length() - 1)
                    {
                        currentSequence.add(input.charAt(i + 1) - '0');
                        currentSequenceIndex = 0;
                        i++;        // both this increment and the for-loop increment will result in the index going up by 2
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                sequences.add(currentSequence);
                currentSequence = new IntSequence();
                currentSequence.add(input.charAt(i) - '0');
                currentSequenceIndex = 0;
            }
        }

        int highestSum = 0;
        int highestSumIndex = 0;
        for (int i = 0; i < sequences.size(); i++)
        {
            int currentSequenceSum = sequences.get(i).sum();

            if (currentSequenceSum > highestSum)
            {
                highestSum = currentSequenceSum;
                highestSumIndex = i;
            }
        }

        return sequences.get(highestSumIndex).toString();
    }
}
