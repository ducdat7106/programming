#include <iostream>

using namespace std;

bool check(int number);

int main()
{
    cout << check(103) << endl;
    cout << check(90) << endl;
    cout << check(89) << endl;

    return 0;
}

bool check(int number)
{
    if (abs(number - 100) <= 10 || abs(number - 200) <= 10)
        return true;
    return false;
}