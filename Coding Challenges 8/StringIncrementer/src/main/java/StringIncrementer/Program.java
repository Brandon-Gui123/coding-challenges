package StringIncrementer;

public class Program
{
    public static void main(String[] args)
    {
        printIncrementStringResult("bar");
        printIncrementStringResult("foo09");
    }

    public static String incrementString(String input)
    {
        if (input == null)
            throw new IllegalArgumentException("cannot increment null input");

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

    public static void printIncrementStringResult(String input)
    {
        System.out.printf("%s\t->\t%s%n", input, incrementString(input));
    }
}
