#include <iostream>

using namespace std;

string test(string s);

int main()
{
    cout << test("python") << endl;
    cout << test("ython1") << endl;
    cout << test("jsthon") << endl;
    cout << test("sytson") << endl;

    return 0;
}

string test(string s)
{
    if (s.substr(1, 2) == "yt")
    {
        s.erase(1, 2);
    }
    
    return s;
}