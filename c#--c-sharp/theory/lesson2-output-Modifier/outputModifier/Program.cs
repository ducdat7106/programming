using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace outputModifier
{
    internal class OutParameter
    {
        static void Main(string[] args)
        {
            string name = "";
            int age = 0;
            float mark = 0;

            GetUserInfo(out name, out age, out mark);
            ShowResult(name, age, mark);
        }

        private static void GetUserInfo(out string name, out int age, out float mark)
        {
            Console.WriteLine("Nhap ten: ");
            name = Console.ReadLine();

            Console.WriteLine("Nhap tuoi: ");
            age = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Nhap diem: ");
            mark = Convert.ToSingle(Console.ReadLine());
        }

        private static void ShowResult(string name, int age, float mark)
        {
            Console.WriteLine("Name: " + name);
            Console.WriteLine("Age: " + age);
            Console.WriteLine("MArk: " + mark);
        }

    }
}
