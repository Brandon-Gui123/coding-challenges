public class PatternFinder
{
    public static int findNextNumber(int[] numberPattern)
    {
        // let's start simple by evaluating addition number patterns
        // we need to calculate the difference between each number
        boolean isAdditionNumberPattern = true;

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
                //System.out.println("This is not an addition number pattern!");
                isAdditionNumberPattern = false;
                break;
            }
        }

        if (isAdditionNumberPattern)
        {
            // the next number can be predicted by adding the difference to the last element in the array
            return numberPattern[numberPattern.length - 1] + difference;
        }

        // now let's assume our number pattern contains exponent (n^2 where n is the nth element)
        // we first check if n, for all numbers in the array, is raised by power of 2 every time
        // to obtain the power, use log base n
        // to get to base n, use the change of base formula
        // we cannot use the first element because log(1) is invalid,
        // so we use the second element instead
        double power = Math.log(numberPattern[1]) / Math.log(2);

        for (int i = 2; i < numberPattern.length; i++)
        {
            double pow = Math.log(numberPattern[i]) / Math.log(i + 1);

            // inconsistent power
            if (pow != power)
            {
                //System.out.println("Inconsistent power!");
                break;
            }
        }

        // our next number is the length of the array + 1, raised to the calculated power
        return (int)Math.pow(numberPattern.length + 1, power);
    }
}
