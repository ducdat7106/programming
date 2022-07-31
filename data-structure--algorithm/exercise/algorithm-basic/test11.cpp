#include <iostream>

using namespace std;

string test(string s);

int main()
{
    cout<<test("js")<<endl;
    cout<<test("ascd")<<endl;
    cout<<test("j")<<endl;
    cout<<test("kml")<<endl;


    return 0;
}

string test(string s)
{
    string temp;
    size_t len = s.length();

    if (len <= 3)
        return (s + s + s);
    else
    {
        temp = s.substr(0, 3);
        return (temp + s + temp);
    }
}