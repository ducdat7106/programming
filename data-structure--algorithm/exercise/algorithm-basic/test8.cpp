#include <iostream>

using namespace std;
string test(string strings);

int main()
{
    cout<<test("c sharp")<<endl;
    cout<<test("a")<<endl;
    cout<<test("knowledge")<<endl;

    return 0;
}

string test(string strings)
{
    return (strings.length() >= 2) ? (strings.substr(0, 2) + strings.substr(0, 2) + strings.substr(0, 2)+ strings.substr(0, 2)) : strings;
}