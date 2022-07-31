using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace math
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int max=Math.Max(10, 25);
            float min = Math.Min(1.25f, -3.14f);
            double x = -255.255;
            double d=Math.Abs(x);



            Console.WriteLine($"Value Max({10}, {25}) = {max}");
            Console.WriteLine($"Value Max({1.25f}, {-3.14f}) = {min}");
            Console.WriteLine(d);

            Console.WriteLine("Pi = " + Math.PI);
        }
    }
}
