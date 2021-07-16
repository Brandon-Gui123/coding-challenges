public class NumberToWord
{
    private static final String[] SINGLE_DIGIT_NAMES =
    {
            "zero",
            "one",
            "two",
            "three",
            "four",
            "five",
            "six",
            "seven",
            "eight",
            "nine"
    };

    private static final String[] TEN_TO_NINETEEN_NAMES =
    {
            "ten",
            "eleven",
            "twelve",
            "thirteen",
            "fourteen",
            "fifteen",
            "sixteen",
            "seventeen",
            "eighteen",
            "nineteen"
    };

    public static String convert(int number)
    {
        if (number >= 10)
        {
            return TEN_TO_NINETEEN_NAMES[number % 10];
        }
        else
        {
            return SINGLE_DIGIT_NAMES[number];
        }
    }
}
