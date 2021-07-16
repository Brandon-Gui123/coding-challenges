namespace StringInASCII
{
    using System;
    using System.Text;

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }

        public static string ToASCII(string str)
        {
            byte[] bytes = Encoding.ASCII.GetBytes(str);

            string ascii = "";
            foreach (byte b in bytes)
            {
                ascii += b.ToString();
            }

            return ascii;
        }
    }
}
