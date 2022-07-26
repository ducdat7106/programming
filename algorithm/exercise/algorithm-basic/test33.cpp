#include <iostream>

using namespace std;

string test(string s_root, string sample);

int main()
{
    cout << test("thanh hoa", "a") << endl;
    cout << test("xthxxanhx hoxax", "x") << endl;
    cout << test("bthabnh bhoabbbb", "b") << endl;

    return 0;
}

string test(string s_root, string sample)
{
    size_t len = s_root.length();
    for (int i = 1; i < len - 1; i++)
    {
        if (s_root.substr(i, 1) == sample)
        {
            s_root.erase(i, 1);
            i--;
            len--;
        }
    }
    return s_root;
}