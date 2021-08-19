public class Program
{
    public static void main(String[] args)
    {
        String sample = "challenge";
        System.out.print(sample + " : ");
        System.out.println(sortString(sample));

        String sample2 = "$php7";
        System.out.print(sample2 + " : ");
        System.out.println(sortString(sample2));
    }

    public static boolean isSorted(char[] charArr)
    {
        char previousChar = charArr[0];

        for (int i = 1; i < charArr.length; i++)
        {
            // condition is true if the first char is lesser
            // than the second char
            // this means the char array is not sorted
            if (Character.compare(charArr[i], previousChar) < 0)
            {
                return false;
            }

            previousChar = charArr[i];
        }

        return true;
    }

    public static void sortCharacters(char[] charArr)
    {
        // we'll use bubble sort to sort the characters in terms of order on the ASCII
        while (!isSorted(charArr))
        {
            for (int i = 0; i < charArr.length - 1; i++)
            {
                // is the current char more than the char ahead?
                if (Character.compare(charArr[i], charArr[i + 1]) > 0)
                {
                    // the current char needs to be swapped with the char ahead
                    char currentCopy = charArr[i];
                    charArr[i] = charArr[i + 1];
                    charArr[i + 1] = currentCopy;
                }
            }
        }
    }

    public static String sortString(String str)
    {
        char[] charArr = str.toCharArray();
        sortCharacters(charArr);
        return new String(charArr);
    }
}
