namespace PasswordValidator_CSharp
{
    public static class StringExtensions
    {
        public static PasswordValidator Should(this string str)
        {
            return new(str);
        }
    }
}