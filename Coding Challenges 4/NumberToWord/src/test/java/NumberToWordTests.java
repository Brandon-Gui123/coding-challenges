import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class NumberToWordTests
{
    @ParameterizedTest
    @CsvSource({
        "0,     zero",
        "1,     one",
        "2,     two",
        "3,     three",
        "4,     four",
        "5,     five",
        "6,     six",
        "7,     seven",
        "8,     eight",
        "9,     nine"
    })
    void testConvertingSingleDigitNumber(int numberToUse, String expected)
    {
        String word = NumberToWord.convert(numberToUse);
        assertEquals(expected, word);
    }

    @ParameterizedTest
    @CsvSource({
        "10,    ten",
        "11,    eleven",
        "12,    twelve",
        "13,    thirteen",
        "14,    fourteen",
        "15,    fifteen",
        "16,    sixteen",
        "17,    seventeen",
        "18,    eighteen",
        "19,    nineteen"
    })
    void testConvertingNumbersWithOneInTensPlace(int numberToUse, String expected)
    {
        String word = NumberToWord.convert(numberToUse);
        assertEquals(expected, word);
    }

    @ParameterizedTest
    @CsvSource({
        "20, twenty",
        "30, thirty",
        "40, forty",
        "50, fifty",
        "60, sixty",
        "70, seventy",
        "80, eighty",
        "90, ninety"
    })
    void testConvertingNumbersTwentyToNinetyWithZeroInOnesPlace(int numberToUse, String expected)
    {
        String word = NumberToWord.convert(numberToUse);
        assertEquals(expected, word);
    }

    // The main goal of this test is to check if a number, like 32, will give both
    // the name of the tens, thirty, and the name of the ones, two, which
    // will correctly give the word-equivalent of the number, thirty two.
    // By right there is a hyphen between the two words but the sample output
    // given by the challenge has no hyphen and also, we'd probably be able to
    // format the string to put a hyphen later.
    @ParameterizedTest
    @CsvSource({
        "21, twenty one",
        "22, twenty two",
        "23, twenty three",
        "24, twenty four",
        "25, twenty five",
        "26, twenty six",
        "27, twenty seven",
        "28, twenty eight",
        "29, twenty nine"
    })
    void testConvertingNumbersTwentyWithNonZeroOnesPlace(int numberToUse, String expected)
    {
        String word = NumberToWord.convert(numberToUse);
        assertEquals(expected, word);
    }
}
