#include <iostream>

using namespace std;

string test(string s);

int main()
{
    cout << test("dat") << endl;
    cout << test("abcd") << endl;
    cout << test("xy") << endl;

    return 0;
}

string test(string s)
{
    string temp = s.substr(s.length() - 1, 1);
    return (temp + s + temp);
}