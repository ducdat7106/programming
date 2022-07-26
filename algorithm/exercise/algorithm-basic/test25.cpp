#include <iostream>

using namespace std;

string test(string s, int number_copy);

int main()
{
    cout << test("python", 3) << endl;
    cout << test("yeu", 4) << endl;
    cout << test("js", 2) << endl;

    return 0;
}

string test(string s, int number_copy)
{
    string result;
    size_t len = s.length();

    if (len < 3)
    {
        int i = number_copy;
        while (i != 0)
        {
            result += s;
            i--;
        }
    }
    else
    {
        for (int i = 0; i < number_copy; i++)
            result += s.substr(0, 3);
    }

    return result;
}