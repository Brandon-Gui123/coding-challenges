namespace BackwardsPrimeProgram
{
    public static class BackwardsPrimeMethods
    {
        public static bool IsPrime(int number)
        {
            // trial division used here

            for (int i = 2; i < number; i++)
            {
                if (number % i == 0)
                {
                    return false;
                }
            }

            return true;
        }
    }
}