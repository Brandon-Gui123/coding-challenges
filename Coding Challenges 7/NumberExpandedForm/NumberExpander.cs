using System.Collections.Generic;
using System.Text;

namespace NumberExpandedForm
{
    public static class NumberExpander
    {
        public static string Expand(int number)
        {
            List<int> expandedDigits = new();
            int multiplier = 1;

            while (number != 0)
            {
                int digit = number % 10;

                if (digit != 0)
                {
                    expandedDigits.Add(number % 10 * multiplier);
                }
                
                multiplier *= 10;
                number /= 10;
            }

            StringBuilder expandedResultBuilder = new(expandedDigits.Count);

            for (int i = expandedDigits.Count - 1; i >= 0; i--)
            {
                expandedResultBuilder.Append(expandedDigits[i]);

                if (i != 0)
                {
                    expandedResultBuilder.Append(" + ");
                }
            }

            return expandedResultBuilder.ToString();
        }
    }
}