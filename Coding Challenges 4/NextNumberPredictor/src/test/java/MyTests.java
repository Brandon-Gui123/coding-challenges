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
}