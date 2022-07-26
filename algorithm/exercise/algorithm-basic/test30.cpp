#include <iostream>

using namespace std;

int test(string s);

int main()
{
    cout << test("abababcdab") << endl;
    cout << test("abcbsbcdab") << endl;
    cout << test("abababcdmn") << endl;
    cout << test("abbcdab") << endl;

    return 0;
}

int test(string s)
{
    size_t length = s.length();
    int counter = 0;
    for (int i = 0; i < length - 2; i++)
        if (s[i] == s[length - 2] && s[i + 1] == s[length - 1])
            counter++;
    return counter;
}