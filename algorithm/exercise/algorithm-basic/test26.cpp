#include <iostream>

using namespace std;

int test(string str);

int main()
{
    cout << test("bbaaccaag") << endl;
    cout << test("jjkksaaaewr") << endl;
    cout << test("jsaaahhhaaalkaa") << endl;

    return 0;
}

int test(string str)
{
    int counter = 0;

    size_t lengths = str.length();
    for (int i = 0; i < lengths; i++)
        if (str[i] == str[i + 1] && str[i] == 'a')
            counter++;

    return counter;
}