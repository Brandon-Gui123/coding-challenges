import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class MyTests
{
    @Test
    public void someTests()
    {
        Assertions.assertEquals(10, 10);
    }

    @Test
    public void testThatFails()
    {
        Assertions.assertEquals(1, 2);
    }
}