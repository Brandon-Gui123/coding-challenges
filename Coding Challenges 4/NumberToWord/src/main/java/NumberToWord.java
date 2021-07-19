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

    private static final String[] ELEVEN_TO_NINETEEN_NAMES =
    {
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

    private static final String[] TENS_PLACE_NAMES =
    {
            "ten",
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
                    return getNameOfDigit(hundredsPlace) + " " + HUNDRED + " "
                            + (onesPlace == 0 ? "ten" : getElevenToNineteenNameBasedOnOnesPlace(onesPlace));
                }
                else    // more than one in tens place
                {
                    return getNameOfDigit(hundredsPlace) + " " + HUNDRED + " "
                            + getNameOfTensPlace(tensPlace)
                            + ((onesPlace == 0) ? "" : " " + getNameOfDigit(onesPlace));
                }
            }
            else if (tensPlace == 0 && onesPlace > 0)       // number with zero in tens place but more than 0 for ones
            {
                return getNameOfDigit(hundredsPlace) + " " + HUNDRED + " " + getNameOfDigit(onesPlace);
            }
            else    // number with 0 in tens and ones places
            {
                return getNameOfDigit(hundredsPlace) + " " + HUNDRED;
            }
        }
        else if (number >= 20)
        {
            if (onesPlace != 0)
            {
                return getNameOfTensPlace(tensPlace) + " " + getNameOfDigit(onesPlace);
            }
            else
            {
                return getNameOfTensPlace(tensPlace);
            }
        }
        else if (number >= 10)
        {
            return (number == 10 ? "ten" : getElevenToNineteenNameBasedOnOnesPlace(onesPlace));
        }
        else
        {
            return getNameOfDigit(number);
        }
    }

    private static String getNameOfTensPlace(int tensPlaceValue)
    {
        // -1 so that 1 in tens place corresponds to the first element
        // in the array (so that 10 is ten).
        return TENS_PLACE_NAMES[tensPlaceValue - 1];
    }

    private static String getNameOfDigit(int digit)
    {
        return SINGLE_DIGIT_NAMES[digit];
    }

    private static String getElevenToNineteenNameBasedOnOnesPlace(int onesPlaceValue)
    {
        // -1 so that 1 in ones place corresponds to the first element
        // array, so 11 will correspond to eleven
        return ELEVEN_TO_NINETEEN_NAMES[onesPlaceValue - 1];
    }
}
