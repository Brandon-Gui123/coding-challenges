using System.Collections.Generic;
using System.Text;

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
    
        public static string DashatizeOdds(int integerInput)
        {
            List<int> reversedDigits = IntToReversedDigits(integerInput);

            // 10 is the max number of digits an integer can have
            // since more than that means the value is bigger than int.MaxValue
            Dictionary<int, DashesPlacement> indexAndDashes = new(10);

            // go through each digit in reverse order
            for (int i = reversedDigits.Count - 1; i >= 0; i--)
            {
                if (reversedDigits[i] % 2 != 0)
                {
                    // this odd digit shall have a left dash if
                    // 1. it isn't the first digit
                    // 2. the previous digit isn't odd
                    bool hasLeftDash = (i != 0) && (i > 0 && reversedDigits[i - 1] % 2 != 1);

                    // this odd digit shall have a right dash if
                    // 1. it isn't the last digit
                    bool hasRightDash = i < reversedDigits.Count - 1;

                    DashesPlacement dashesPlacement = new(hasLeftDash, hasRightDash, reversedDigits[i]);
                    indexAndDashes.Add(i, dashesPlacement);
                }
            }

            // I'll be continuously building upon the string
            // so a StringBuilder may come in handy here
            StringBuilder dashatizedBuilder = new(reversedDigits.Count);

            for (int i = reversedDigits.Count - 1; i >= 0; i--)
            {
                if (indexAndDashes.TryGetValue(i, out var dashesPlacement))
                {
                    if (dashesPlacement.HasLeftDash)
                        dashatizedBuilder.Append('-');

                    dashatizedBuilder.Append(dashesPlacement.Digit);

                    if (dashesPlacement.HasRightDash)
                        dashatizedBuilder.Append('-');
                }
                else
                {
                    dashatizedBuilder.Append(reversedDigits[i]);
                }
            }

            return dashatizedBuilder.ToString();
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
