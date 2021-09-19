using NUnit.Framework;
using BackwardsPrimeProgram;
using FluentAssertions;

namespace BackwardsPrimeTests
{
    public class IsEmirpTests
    {
        [Test]
        public void Given13_ReturnsTrue()
        {
            bool result = BackwardsPrimeMethods.IsEmirp(13);
            result.Should().BeTrue(because: "13 and 31 are prime numbers");
        }

        [Test]
        public void Given2_ReturnsFalse()
        {
            bool result = BackwardsPrimeMethods.IsEmirp(2);
            result.Should().BeFalse(because: "an emirp must have at least 2 digits");
        }

        [Test]
        public void Given11_ReturnsFalse()
        {
            bool result = BackwardsPrimeMethods.IsEmirp(11);
            result.Should().BeFalse(because: "both the number and reversed number must create unique numbers");
        }

        [Test]
        public void Given23_ReturnsFalse()
        {
            bool result = BackwardsPrimeMethods.IsEmirp(23);
            result.Should().BeFalse(because: "while 23 is a prime number, the reversed number (32) is not");
        }
    
        [Test]
        public void Given1_ReturnsFalse()
        {
            bool result = BackwardsPrimeMethods.IsEmirp(1);
            result.Should().BeFalse(because: "1 is not a valid prime number");
        }

        [Test]
        public void GivenNegative1_ReturnsFalse()
        {
            bool result = BackwardsPrimeMethods.IsEmirp(-1);
            result.Should().BeFalse(because: "negative numbers are not valid prime numbers");
        }
    }
}
