public class EntryPoint
{
    public static void main(String[] args)
    {
        printResults(6);
        printResults(12);
    }

    public static int getTrailingZeroesCountInFactorialOf(int num)
    {
        return num / 5;
    }

    public static void printResults(int input)
    {
        System.out.printf("%d\t->\t%d%n", input, getTrailingZeroesCountInFactorialOf(input));
    }
}
