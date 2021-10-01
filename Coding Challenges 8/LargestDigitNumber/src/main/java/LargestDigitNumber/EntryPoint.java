package LargestDigitNumber;

import java.util.ArrayList;

public class EntryPoint
{
    public static void main(String[] args)
    {
        printInChallengeExampleFormat("1234567890");
    }

    public static String getLargest5Sequence(String input)
    {
        if (input.isBlank())
        {
            return "";
        }
        else if (!inputContainsOnlyNumbers(input))
        {
            throw new IllegalArgumentException("input can only contain digits");
        }

        ArrayList<IntSequence> sequences = findConsecutiveSequences(input, 5);

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

    public static ArrayList<IntSequence> findConsecutiveSequences(String input, int sequenceLength)
    {
        ArrayList<IntSequence> sequences = new ArrayList<>();

        // we need at least one digit in the current sequence, so we can
        // compare with other digits in the input
        IntSequence currentSequence = new IntSequence();
        currentSequence.ensureCapacity(sequenceLength);

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

                if (currentSequence.size() == sequenceLength)
                {
                    sequences.add(currentSequence);

                    if (currentInputIndex < input.length() - 2)
                    {
                        currentSequence = new IntSequence();
                        currentSequence.ensureCapacity(sequenceLength);
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

        return sequences;
    }

    public static void printInChallengeExampleFormat(String input)
    {
        System.out.println("Input: ");
        System.out.println(input);
        System.out.println();
        System.out.println("Output: ");
        System.out.println(getLargest5Sequence(input));
    }

    public static boolean inputContainsOnlyNumbers(String input)
    {
        for (int i = 0; i < input.length(); i++)
        {
            char inputChar = input.charAt(i);

            if (!Character.isDigit(inputChar))
            {
                return false;
            }
        }

        return true;
    }
}
