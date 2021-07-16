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
}
