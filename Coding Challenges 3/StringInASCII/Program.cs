namespace StringInASCII
{
    using System;
    using System.Text;

    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("- programmer: ");
            Console.Write(ToASCII("programmer"));
            Console.WriteLine();

            Console.Write("- plus: ");
            Console.Write(ToASCII("plus"));
            Console.WriteLine();
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
