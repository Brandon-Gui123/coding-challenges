package Mumbler;

public class Main
{
    public static void main(String[] args)
    {
        System.out.println("Darn");
    }

    public static String mumble(String input)
    {
        StringBuilder stringBuilder = new StringBuilder();
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
}
