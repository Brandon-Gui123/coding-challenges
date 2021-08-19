public class PatternFinder
{
    public static int findNextNumber(int[] numberPattern)
    {
        // let's start simple by evaluating addition number patterns
        // we need to calculate the difference between each number

        // start by calculating the difference between the last 2 numbers in the pattern
        int difference = numberPattern[numberPattern.length - 1] - numberPattern[numberPattern.length - 2];

        // start with the last second element and stop at the second element
        for (int i = numberPattern.length - 2; i >= 1; i--)
        {
            // if the difference is equal to what we calculated above,
            // the pattern must be an addition number pattern,
            // if not, then this must be another pattern
            if (numberPattern[i] - numberPattern[i - 1] != difference)
            {
                System.out.println("This is not an addition number pattern!");
                break;
            }
        }

        // the next number can be predicted by adding the difference to the last element in the array
        return numberPattern[numberPattern.length - 1] + difference;
    }
}
