using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace helloWord
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello word ");

            string msg = "Hello    Word";
            Console.WriteLine(msg.Length); //get length string
            Console.WriteLine(msg.ToUpper());//all contant write hoa
            Console.WriteLine(msg.ToLower());
            Console.WriteLine(msg.Trim().ToLower());//clear space at 2 head


        }
    }
}
