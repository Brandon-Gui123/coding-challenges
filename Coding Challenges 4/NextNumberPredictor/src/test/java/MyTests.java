import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class MyTests
{
    // Test on number patterns where the same number just keeps getting added
    @Test
    public void testAdditionPattern()
    {
        int[] numberPattern = { 4, 8, 12, 16 };
        int nextNumber = PatternFinder.findNextNumber(numberPattern);

        Assertions.assertEquals(20, nextNumber);
    }

    // Test on square number patterns (e.g. 1, 4, 9...)
    @Test
    public void testSquareNumbersPattern()
    {
        int[] numberPattern = { 1, 4, 9, 16 };
        int nextNumber = PatternFinder.findNextNumber(numberPattern);

        Assertions.assertEquals(25, nextNumber);
    }
}