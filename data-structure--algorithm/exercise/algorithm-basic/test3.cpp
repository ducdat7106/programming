#include <iostream>

using namespace std;

int check_number(int num1, int num2);
bool test(int x, int y);

int main()
{
    cout << check_number(30, 0) << endl;
    cout << check_number(25, 5) << endl;
    cout << check_number(20, 30) << endl;
    cout << check_number(25, 20) << endl;

    return 0;
}

int check_number(int num1, int num2)
{
    if (num1 == 30 || num2 == 30 || (num1 + num2) == 30)
        return 1;
    else
        return 0;
}

bool test(int x, int y)
{
    return x == 30 || y == 30 || ((x + y) == 30);
}