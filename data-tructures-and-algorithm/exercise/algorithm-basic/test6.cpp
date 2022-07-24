#include <iostream>

using namespace std;

void test(string &string_source, int position);

int main()
{
    string str = "hello world";
    string str1 = "nguyen duc dat";

    test(str, 4);
    test(str1, 6);

    cout << str << endl;
    cout << str1 << endl;

    return 0;
}

void test(string &string_source, int position)
{
    string_source.erase(position, 1);
}

