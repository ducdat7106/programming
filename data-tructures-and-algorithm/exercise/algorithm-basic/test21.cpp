#include <iostream>

using namespace std;

unsigned int test(unsigned int x, unsigned int y);

int main()
{
    cout << test(20, 30) << endl;
    cout << test(40, 30) << endl;
    cout << test(10, 30) << endl;
    cout << test(28, 28) << endl;
    cout << test(24, 29) << endl;


    return 0;
}

unsigned int test(unsigned int x, unsigned int y)
{
    if (x < 20 || y < 20 || x > 30 || y > 30)
        return 0;
    else
    {
        return (x >= y) ? x : y;
    }
}