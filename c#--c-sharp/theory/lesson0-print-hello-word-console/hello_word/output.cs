using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace hello_word
{
    internal class output
    {
        class void Main()
        {
            //lesson 10
            int a=Convert.ToInt32(Console.ReadLine());//nhap so a
            int b = Convert.ToInt32(Console.ReadLine());//nhap so a
            int sum = a + b;

            //display the value on the screen
            //1. away
            Console.WriteLine("C1 Tong a+b= "+sum);

            //2. away
            Console.WriteLine("C2 Tong {0} + {1} = {2}", a,b,sum);

            //3. away
            Console.WriteLine($"C2 Tong {a} + {b} = {sum}");

        }
    }
}
