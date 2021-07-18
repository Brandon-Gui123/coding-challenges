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

    private static final String[] BY_TEN_NAMES =
    {
            "twenty",
            "thirty",
            "forty",
            "fifty",
            "sixty",
            "seventy",
            "eighty",
            "ninety"
    };

    private static final String HUNDRED = "hundred";

    public static String convert(int number)
    {
        int hundredsPlace = number / 100;
        int tensPlace = (number / 10) % 10;
        int onesPlace = number % 10;

        if (number >= 100)
        {
            if (tensPlace > 0)    // number with non-zero in tens place
            {
                if (tensPlace == 1)   // one in tens place
                {
                    return SINGLE_DIGIT_NAMES[hundredsPlace] + " " + HUNDRED + " "
                            + TEN_TO_NINETEEN_NAMES[number % 10];
                }
                else    // more than one in tens place
                {
                    return SINGLE_DIGIT_NAMES[hundredsPlace] + " " + HUNDRED + " "
                            + BY_TEN_NAMES[tensPlace - 2]
                            + ((number % 10 == 0) ? "" : " " + SINGLE_DIGIT_NAMES[number % 10]);
                }
            }
            else if (tensPlace == 0 && number % 10 > 0)       // number with zero in tens place but more than 0 for ones
            {
                return SINGLE_DIGIT_NAMES[hundredsPlace] + " " + HUNDRED + " " + SINGLE_DIGIT_NAMES[number % 10];
            }
            else    // number with 0 in tens and ones places
            {
                return SINGLE_DIGIT_NAMES[hundredsPlace] + " " + HUNDRED;
            }
        }
        else if (number >= 20)
        {
            if (onesPlace != 0)
            {
                // we have to reduce the number by 2 so that
                // the index will map correctly
                // (e.g. in 20, we have to take away 2 from 2 in 20, so that we get 0,
                // which corresponds to the first element "twenty").
                return BY_TEN_NAMES[tensPlace - 2] + " " + SINGLE_DIGIT_NAMES[onesPlace];
            }
            else
            {
                return BY_TEN_NAMES[tensPlace - 2];
            }
        }
        else if (number >= 10)
        {
            return TEN_TO_NINETEEN_NAMES[number % 10];
        }
        else
        {
            return SINGLE_DIGIT_NAMES[number];
        }
    }
}
