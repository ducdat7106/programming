#include <iostream>

using namespace std;

bool test(int x, int y);

int main()
{
    cout << test(20, 84) << endl;
    cout << test(14, 50) << endl;
    cout << test(45, 11) << endl;
    cout << test(25, 40) << endl;
    cout << test(35, 20) << endl;

    return 0;
}

bool test(int x, int y)
{
    if ((x >= 20 && x <= 50 && (y < 20 || y > 50)) || ((x < 20 || x > 50) && y >= 20 && y <= 50))
        return true;
    else
        return false;
}