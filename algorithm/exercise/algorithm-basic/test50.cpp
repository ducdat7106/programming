#include <iostream>

using namespace std;

bool test(int x, int y);

int main()
{
    cout << test(11, 21) << endl;
    cout << test(45, 21) << endl;
    cout << test(32, 21) << endl;

    return 0;
}

bool test(int x, int y)
{
    int dozen_x = x / 10;
    int unit_x = x % 10;

    int dozen_y = y / 10;
    int unit_y = y % 10;

    if (dozen_x == dozen_y || dozen_x == unit_y || unit_x == dozen_y || unit_x == unit_y)
        return true;
    return false;
}