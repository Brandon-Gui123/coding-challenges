namespace BackwardsPrimeProgram
{
    public static class BackwardsPrimeMethods
    {
        public static bool IsPrime(int number)
        {
            // numbers lesser than 2 aren't valid prime numbers
            if (number < 2)
            {
                return false;
            }

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