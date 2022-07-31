#include <iostream>

using namespace std;

bool test(unsigned int x, unsigned int y);

int main()
{
    cout << test(42, 122) << endl;
    cout << test(12, 2) << endl;
    cout << test(2, 2) << endl;
    cout << test(234, 455) << endl;

    return 0;
}

bool test(unsigned int x, unsigned int y)
{
    return (((x % 10) == (y % 10)) ? true : false);
}