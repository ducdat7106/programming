#include <iostream>

using namespace std;

string test(string str);

int main()
{
    cout<<test("if else")<<endl;
    cout<<test("else")<<endl;
    
    return 0;
}

string test(string str)
{
    if (str.length() > 2 && str.substr(0, 2) == "if")
        return str;
    else
        return ("if " + str);
}