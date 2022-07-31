#include <iostream>

using namespace std;

string test(string string_root, int number_copy);

int main()
{
    cout << test("js", 5) << endl;
    cout << test("abc", 6) << endl;
    cout << test("min_max", 4) << endl;

    return 0;
}

string test(string string_root, int number_copy)
{
    string result;

    for (int i = 0; i < number_copy; i++)
        result += string_root;

    return result;
}