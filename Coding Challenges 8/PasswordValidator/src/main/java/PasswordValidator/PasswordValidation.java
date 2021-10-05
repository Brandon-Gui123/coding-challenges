package PasswordValidator;

public class PasswordValidation
{
    public static boolean isLengthAtLeast(String password, int minLength)
    {
        return password.length() >= minLength;
    }

    public static boolean containsLowercase(String password)
    {
        for (int i = 0; i < password.length(); i++)
        {
            var currentChar = password.charAt(i);
            if (Character.isLowerCase(currentChar))
            {
                return true;
            }
        }

        return false;
    }

    public static boolean containsUppercase(String password)
    {
        for (int i = 0; i < password.length(); i++)
        {
            var currentChar = password.charAt(i);
            if (Character.isUpperCase(currentChar))
            {
                return true;
            }
        }

        return false;
    }

    public static boolean containsDigit(String password)
    {
        for (int i = 0; i < password.length(); i++)
        {
            var currentChar = password.charAt(i);
            if (Character.isDigit(currentChar))
            {
                return true;
            }
        }

        return false;
    }

    public static boolean isValidPassword(String password)
    {
        return isLengthAtLeast(password, 6)
                && containsLowercase(password)
                && containsUppercase(password)
                && containsDigit(password);
    }
}
