#include <iostream>

using namespace std;

bool test(string str);

int main()
{
    cout << test("C#") << endl;
    cout << test("C# different") << endl;
    cout << test("C++ ") << endl;
    cout << test("C# C#") << endl;

    return 0;
}

bool test(string str)
{
    return (str.length() < 3 && str == "C#") || (str.substr(0, 2) == "C#" && str[2] == ' ');
}