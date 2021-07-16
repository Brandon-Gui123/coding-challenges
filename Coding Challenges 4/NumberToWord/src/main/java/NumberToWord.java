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

    public static String convert(int number)
    {
        return SINGLE_DIGIT_NAMES[number];
    }
}
