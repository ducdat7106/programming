#include <iostream>

using namespace std;

string test(string str);

int main()
{
    cout << test("abcd") << endl;
    cout << test("abc") << endl;
    cout << test("a") << endl;

    return 0;
}

string test(string str)
{
    string result;
    for (int i = 0; i < str.length(); i++)
    {
        result += str.substr(0, i + 1);
    }
    return result;
}