using BackwardsPrimeProgram;
using FluentAssertions;
using NUnit.Framework;

namespace BackwardsPrimeTests
{
    public class IsPrimeTests
    {
        [Test]
        public void TwoIsPrimeNumber()
        {
            bool result = BackwardsPrimeMethods.IsPrime(2);
            result.Should().BeTrue(because: "2 is divisible by only 1 and itself");
        }

        [Test]
        public void ThreeIsPrimeNumber()
        {
            bool result = BackwardsPrimeMethods.IsPrime(3);
            result.Should().BeTrue(because: "3 is divisible by only 1 and itself");
        }

        [Test]
        public void FiveIsPrimeNumber()
        {
            bool result = BackwardsPrimeMethods.IsPrime(5);
            result.Should().BeTrue(because: "5 is divisible by only 1 and itself");
        }

        [Test]
        public void FourIsNotPrimeNumber()
        {
            bool result = BackwardsPrimeMethods.IsPrime(4);
            result.Should().BeFalse(because: "4 is divisible by 2");
        }

        [Test]
        public void NineIsNotPrimeNumber()
        {
            bool result = BackwardsPrimeMethods.IsPrime(9);
            result.Should().BeFalse(because: "9 is divisible by 3");
        }
    }
}
