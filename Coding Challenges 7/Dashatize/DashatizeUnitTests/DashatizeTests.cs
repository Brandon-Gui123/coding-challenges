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
    }
}