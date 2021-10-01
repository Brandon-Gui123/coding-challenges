package Mumbler;

public class Main
{
    public static void main(String[] args)
    {
        printInChallengeFormat("abcdefghijklmnopqrstuvwxyz");
        printInChallengeFormat("plus");
    }

    public static String mumble(String input)
    {
        int mumbledStringLength = 0;
        for (int i = 0; i < input.length(); i++)
        {
            mumbledStringLength += i + 1;
        }
        mumbledStringLength += input.length() - 1;

        StringBuilder stringBuilder = new StringBuilder(mumbledStringLength);
        for (int i = 0; i < input.length(); i++)
        {
            char currentChar = input.charAt(i);
            stringBuilder.append(Character.toUpperCase(currentChar));

            for (int j = 0; j < i; j++)
            {
                stringBuilder.append(Character.toLowerCase(currentChar));
            }

            if (i < input.length() - 1)
            {
                stringBuilder.append('-');
            }
        }

        return stringBuilder.toString();
    }

    public static void printInChallengeFormat(String input)
    {
        System.out.printf("Input: %s", input);
        System.out.println();
        System.out.printf("Output: %s", mumble(input));
        System.out.println();
    }
}
