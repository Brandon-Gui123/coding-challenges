package StringIncrementer;

public class Program
{
    public static String incrementString(String input)
    {
        char lastChar = input.charAt(input.length() - 1);
        if (Character.isDigit(lastChar))
        {
            int lastCharAsInt = lastChar - '0';
            lastCharAsInt++;
            return input.substring(0, input.length() - 1) + lastCharAsInt;
        }
        else
        {
            return input + '1';
        }
    }
}
