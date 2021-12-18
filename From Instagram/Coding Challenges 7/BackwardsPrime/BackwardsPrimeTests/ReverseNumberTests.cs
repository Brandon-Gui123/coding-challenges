using BackwardsPrimeProgram;
using FluentAssertions;
using NUnit.Framework;

namespace BackwardsPrimeTests
{
    public class ReverseNumberTests
    {
        [Test]
        public void Given123_ReversedResultIs321()
        {
            int result = BackwardsPrimeMethods.ReverseNumber(123);
            result.Should().Be(321, because: $"the reverse of 123 is 321");
        }

        [Test]
        public void Given100_ReversedResultIs1()
        {
            int result = BackwardsPrimeMethods.ReverseNumber(100);
            result.Should()
                  .Be(1, because: "while the reverse of 100 is 001, the preceding zeroes are omitted");
        }

        [Test]
        public void Given1_ReversedResultIs1()
        {
            int result = BackwardsPrimeMethods.ReverseNumber(1);
            result.Should().Be(1, because: "there's only 1 digit");
        }

        [Test]
        public void GivenNegative123_ReversedResultIsNegative321()
        {
            int result = BackwardsPrimeMethods.ReverseNumber(-123);
            result.Should().Be(-321, because: "the reverse of 123 is 321, and the sign should be kept the same");
        }
    }
}
