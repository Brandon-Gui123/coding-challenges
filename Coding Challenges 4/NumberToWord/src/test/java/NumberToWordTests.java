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

    @ParameterizedTest
    @CsvSource({
        "100, one hundred",
        "200, two hundred",
        "300, three hundred",
        "400, four hundred",
        "500, five hundred",
        "600, six hundred",
        "700, seven hundred",
        "800, eight hundred",
        "900, nine hundred"
    })
    void testConvertingHundredsWithZeroTensAndOnes(int numberToUse, String expected)
    {
        String word = NumberToWord.convert(numberToUse);
        assertEquals(expected, word);
    }

    // Main goal is to check if the method is able to detect a non-zero value
    // in the tens place and give the correct name of the number
    @ParameterizedTest
    @CsvSource({
        "110, one hundred ten",
        "120, one hundred twenty",
        "130, one hundred thirty",
        "140, one hundred forty",
        "150, one hundred fifty",
        "160, one hundred sixty",
        "170, one hundred seventy",
        "180, one hundred eighty",
        "190, one hundred ninety"
    })
    void testConvertingHundredsWithTensAndZeroOnes(int numberToUse, String expected)
    {
        String word = NumberToWord.convert(numberToUse);
        assertEquals(expected,word);
    }

    @ParameterizedTest
    @CsvSource({
        "101, one hundred one",
        "102, one hundred two",
        "103, one hundred three",
        "104, one hundred four",
        "105, one hundred five",
        "106, one hundred six",
        "107, one hundred seven",
        "108, one hundred eight",
        "109, one hundred nine",
    })
    void testConvertingHundredsWithOnesAndZeroTens(int numberToUse, String expected)
    {
        String word = NumberToWord.convert(numberToUse);
        assertEquals(expected, word);
    }
}
