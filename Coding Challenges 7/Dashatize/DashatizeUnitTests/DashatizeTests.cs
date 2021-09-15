using NUnit.Framework;
using DashatizeUtils;
using FluentAssertions;

namespace DashatizeUnitTests
{
    public class Tests
    {
        [Test]
        public void DashatizeWithBothDashes()
        {
            const int input = 22322;
            string result = Dashatize.DashatizeOdds(input);
            result.Should().Be(
                "22-3-22",
                because: "there is just 1 odd number and there is space for left and right dashes"
            );
        }

        [Test]
        public void DashatizeOddNumberThatIsFirst()
        {
            const int input = 3000;
            string result = Dashatize.DashatizeOdds(input);
            result.Should().Be(
                "3-000",
                because: "the odd number is the first digit, so there aren't any left dashes "
                         + "but there's space on the right so a right dash should be present"
            );
        }
    }
}