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
    }
}
