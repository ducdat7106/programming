#include <iostream>

using namespace std;

bool test(string str);

int main()
{
    cout << test("aaaacssa") << endl;
    cout << test("abaa") << endl;
    cout << test("bvccaa") << endl;

    return 0;
}

bool test(string str)
{
    int positions = str.find_first_of('a');
    return (str[positions + 1] == 'a' ? true : false);
}