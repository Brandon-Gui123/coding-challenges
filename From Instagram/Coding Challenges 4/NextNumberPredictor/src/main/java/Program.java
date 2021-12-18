public class Program
{
    public static void main(String[] args)
    {
        int[] numberPattern1 = { 1, 4, 9, 16 };

        for (int num : numberPattern1)
        {
            System.out.print(num + " ");
        }
        System.out.print(": ");
        System.out.println(PatternFinder.findNextNumber(numberPattern1));

        int[] numberPattern2 = { 4, 8, 12, 16 };

        for (int num : numberPattern2)
        {
            System.out.print(num + " ");
        }
        System.out.print(": ");
        System.out.println(PatternFinder.findNextNumber(numberPattern2));
    }
}
