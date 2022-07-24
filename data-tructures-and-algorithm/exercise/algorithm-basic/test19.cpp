#include <iostream>

using namespace std;

int test(int x, int y);

int main()
{
    cout << test(78, 95) << endl;
    cout << test(95, 95) << endl;
    cout << test(99, 70) << endl;
    cout << test(10, 70) << endl;

    return 0;
}

int test(int x, int y)
{
    if (x == y)
        return 0;
    else
    {
        return ((abs(x - 100) > abs(y - 100)) ? y : x);
    }
}