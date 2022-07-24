#include <iostream>

using namespace std;

string test(string s);

int main()
{
    cout << test("python") << endl;
    cout << test("a") << endl;
    cout << test("js") << endl;
    cout << test("html") << endl;

    return 0;
}

string test(string s)
{
    string result;
    for (int i = 0; i < s.length(); i++)
        if (i % 2 == 0)
            result += s[i];
    return result;
}