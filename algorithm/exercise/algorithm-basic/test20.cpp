#include <iostream>

using namespace std;

bool test(int x, int y);

int main()
{
    cout << test(78, 95) << endl;
    cout << test(25, 35) << endl;
    cout << test(40, 50) << endl;
    cout << test(55, 60) << endl;

    return 0;
}

bool test(int x, int y)
{
    return ((x >= 40 && y >= 40 && x <= 50 && y <= 50) || (x >= 50 && y >= 50 && x <= 60 && y <= 60));
}