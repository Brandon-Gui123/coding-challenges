using System.Collections.Generic;

namespace DashatizeUtils
{
    public static class Dashatize
    {
        private class DashesPlacement
        {
            public bool HasLeftDash { get; init; }
            public bool HasRightDash { get; init; }
            public int Digit { get; init; }

            public DashesPlacement(bool hasLeftDash, bool hasRightDash, int digit)
            {
                HasLeftDash = hasLeftDash;
                HasRightDash = hasRightDash;
                Digit = digit;
            }
        }

        private static List<int> IntToReversedDigits(int integer)
        {
            // the maximum number of digits an integer can have
            // is 10, which is the number of digits that
            // int.MaxValue has
            List<int> digitsReversed = new(10);

            do
            {
                digitsReversed.Add(integer % 10);
                integer /= 10;
            }
            while (integer != 0);

            return digitsReversed;
        }
    }
}
