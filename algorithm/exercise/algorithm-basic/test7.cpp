#include <iostream>

using namespace std;

string test(string str);

int main()
{
    cout << test("abcd") << endl;
    cout << test("a") << endl;
    cout << test("rgb") << endl;
    cout << test("dat") << endl;
    cout << test("xy") << endl;

    
    
    return 0;
}

string test(string str)
{
    return (str.length() > 1) ? (str.substr(str.length() - 1, 1) + str.substr(1, str.length() - 2) + str.substr(0, 1)) : str;
}