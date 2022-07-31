#include <iostream>

using namespace std;

int test(int x, int y);

int main()
{
    cout << test(8, 22) << endl;
    cout << test(22, 22) << endl;
    cout << test(30, 22) << endl;

    return 0;
}

int test(int x, int y)
{
    if (x == y)
        return 0;
    else if (x % 7 == y % 7)
        return (x > y) ? y : x;
    else
        return (x > y) ? x : y;
}