package PasswordValidator;

public class EntryPoint
{
    public static void main(String[] args)
    {
        printValidationResults("4fdg5Fj3");
        printValidationResults("dsF43");
    }

    public static void printValidationResults(String inputPassword)
    {
        System.out.printf(
                "%s\t->\t%s%n",
                inputPassword,
                PasswordValidation.isValidPassword(inputPassword)
        );
    }
}
