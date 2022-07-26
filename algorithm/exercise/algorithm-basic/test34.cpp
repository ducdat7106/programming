#include <iostream>

using namespace std;

string test(string str);

int main()
{
    cout << test("opencv-python") << endl;
    return 0;
}

string test(string str)
{
    size_t len = str.length();
    string result;

    int i = 0;
    while (i <= len)
    {
        result += str[i];

        if (i % 2 == 0)
            i++;
        else
            i += 3;
    }

    return result;
}