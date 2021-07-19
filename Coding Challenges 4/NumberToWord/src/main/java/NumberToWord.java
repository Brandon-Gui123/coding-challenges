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
        if (number == 0)
        {
            // this is the only time when we need to say "zero"
            return "zero";
        }

        int hundredsPlace = number / 100;
        int tensPlace = (number / 10) % 10;
        int onesPlace = number % 10;

        String numberName = "";

        if (hundredsPlace > 0)
        {
            numberName += getNameOfDigit(hundredsPlace) + " " + HUNDRED;

            // space for readability
            if (tensPlace > 0 || onesPlace > 0)
            {
                numberName += " ";
            }
        }

        if (tensPlace > 0)
        {
            if (tensPlace == 1 && onesPlace > 0)
            {
                // we have to say eleven instead of ten one here
                // and so on for the others
                numberName += getElevenToNineteenNameBasedOnOnesPlace(onesPlace);

                // we're already done here
                return numberName;
            }
            else
            {
                numberName += getNameOfTensPlace(tensPlace);
            }

            // space for readability
            if (onesPlace > 0)
            {
                numberName += " ";
            }
        }

        if (onesPlace > 0)
        {
            numberName += getNameOfDigit(onesPlace);
        }

        return numberName;
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
