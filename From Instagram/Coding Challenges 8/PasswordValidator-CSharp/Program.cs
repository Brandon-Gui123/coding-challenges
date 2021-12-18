using System;

namespace PasswordValidator_CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            PrintPasswordValidationResult("4fdg5Fj3");
            PrintPasswordValidationResult("dsF43");
        }

        private static void PrintPasswordValidationResult(string password)
        {
            bool isValid = password.Should()
                                   .HaveAtLeastLength(6)
                                   .ContainNumbers()
                                   .ContainLowercaseChars()
                                   .ContainUppercaseChars();
            
            if (isValid)
            {
                Console.WriteLine($"\"{password}\" is a valid password!");
            }
            else
            {
                Console.WriteLine($"\"{password}\" is not a valid password!");
            }
        }
    }
}
