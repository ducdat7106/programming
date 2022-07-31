#include <iostream>

using namespace std;
int test(string s1, string s2);

int main()
{
    cout << test("abcdefgh", "abeeeeeefg");
    return 0;
}

int test(string s1, string s2)
{
    int counter = 0;

    for (int i = 0; i < s1.length() - 1; i++)
    {
        string temp_substr = s1.substr(i, 2);
        for (int j = 0; j < s2.length() - 1; j++)
        {
            if (temp_substr == s2.substr(j, 2))
                counter++;
        }
    }

    return counter;
}