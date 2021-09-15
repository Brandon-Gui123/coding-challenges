﻿using System;
using System.Collections.Generic;
using System.Text;

namespace DashatizeUtils
{
    class DashesPlacement
    {
        public bool HasLeftDash { get; init; }
        public bool HasRightDash { get; init; }
        public int Digit { get; init; }

        public DashesPlacement(bool leftDash, bool rightDash, int digit)
        {
            HasLeftDash = leftDash;
            HasRightDash = rightDash;
            Digit = digit;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int input = 274;

            // extract each integer in the input and
            // put it in a list
            int inputCopy = input;
            List<int> digits = new();
            do
            {
                // TODO Can we optimize this? (append to end of list but all for loops to use reversed iteration?)
                // Insertion point is at the beginning of the list, meaning
                // every invocation is an O(n) operation.
                // This makes this do-while loop an O(n^2) operation.
                // If we call Add(), we might be able to do a O(1) operation
                // (if we are able to reserve enough capacity)
                // (maybe reserve 10 digits? because int.MaxValue is 10 digits?)
                digits.Insert(0, inputCopy % 10);
                inputCopy /= 10;
            }
            while (inputCopy != 0);

            Dictionary<int, DashesPlacement> indexDashesPlacement = new();

            // go through each digit
            for (int i = 0; i < digits.Count; i++)
            {
                if (digits[i] % 2 != 0)
                {
                    // first digit OR previous is odd
                    bool isFirstDigit = i == 0;
                    bool previousIsOdd = i > 0 && digits[i - 1] % 2 != 0;

                    bool leftDash = true;

                    if (isFirstDigit || previousIsOdd)
                    {
                        // do not put a left dash
                        leftDash = false;
                    }

                    // last digit
                    bool isLastDigit = i == digits.Count - 1;

                    bool rightDash = true;
                    if (isLastDigit)
                    {
                        // do not put a right dash
                        rightDash = false;
                    }

                    DashesPlacement dashesPlacement = new(leftDash, rightDash, digits[i]);
                    indexDashesPlacement.Add(i, dashesPlacement);
                }
            }

            // time to start the dashatizing process
            StringBuilder dashatizedStringBuilder = new();

            for (int i = 0; i < digits.Count; i++)
            {
                if (indexDashesPlacement.TryGetValue(i, out DashesPlacement dashesPlacement))
                {
                    if (dashesPlacement.HasLeftDash)
                        dashatizedStringBuilder.Append('-');

                    dashatizedStringBuilder.Append(dashesPlacement.Digit);

                    if (dashesPlacement.HasRightDash)
                        dashatizedStringBuilder.Append('-');
                }
                else
                {
                    dashatizedStringBuilder.Append(digits[i]);
                }
            }
        }
    }
}
