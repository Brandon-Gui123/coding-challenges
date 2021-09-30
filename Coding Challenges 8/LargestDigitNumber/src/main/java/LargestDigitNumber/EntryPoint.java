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

        // is 1 since the first element is already in the sequence
        int currentInputIndex = 1;
        int currentSequenceIndex = 0;

        while (currentInputIndex < input.length())
        {
            int previousDigit = currentSequence.get(currentSequenceIndex);
            int currentDigit = input.charAt(currentInputIndex) - '0';

            if ((previousDigit + 1) % 10 == currentDigit)
            {
                currentSequence.add(currentDigit);
                currentSequenceIndex++;

                if (currentSequence.size() == 5)
                {
                    sequences.add(currentSequence);

                    if (currentInputIndex < input.length() - 2)
                    {
                        currentSequence = new IntSequence();
                        currentSequence.add(input.charAt(currentInputIndex + 1) - '0');
                        currentSequenceIndex = 0;
                        currentInputIndex++;
                    }
                    else
                    {
                        // input exhausted!
                        break;
                    }
                }
            }
            else
            {
                if (currentInputIndex < input.length() - 2)
                {
                    // the current sequence is no longer valid
                    currentSequence.clear();
                    currentSequence.add(input.charAt(currentInputIndex + 1) - '0');
                    currentSequenceIndex = 0;
                    currentInputIndex++;
                }
                else
                {
                    // input exhausted!
                    break;
                }
            }

            currentInputIndex++;
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
