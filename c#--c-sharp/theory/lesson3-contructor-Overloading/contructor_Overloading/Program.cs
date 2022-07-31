using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace contructor_Overloading
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int sum = Add(100, 120);
            float s2 = Add(12.1f, 12.6f);
            long s3 = Add(13L, 12L);

            Console.WriteLine(sum);
            Console.WriteLine(s2);
            Console.WriteLine(s3);
        }

        static int Add(int a, int b)
        {
            return a + b;
        }

        static float Add(float a, float b)
        {
            return (a + b);
        }

        static long Add(long a, long b)
        {
            return (a + b);
        }

        static int Add(int a, int b, int c)
        {
            return (a + b + c);
        }
    }
}
