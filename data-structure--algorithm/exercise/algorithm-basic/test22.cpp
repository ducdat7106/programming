#include <iostream>

using namespace std;

bool test(string s);

int main()
{
    cout << test("frizz") << endl;
    cout << test("zane") << endl;
    cout << test("za zz") << endl;
    cout << test("false") << endl;
    cout << test("zzzzzzzzz") << endl;

    return 0;
}

bool test(string s)
{
    int counter = 0;

    for (int i = 0; i < s.length(); i++)
        if (s[i] == 'z') // if(s[i]==122)
            counter++;

    return (counter >= 2 && counter <= 4);
}