#include <iostream>

using namespace std;

bool test(int numbers);

int main()
{
    cout << test(21) << endl;
    cout << test(6) << endl;
    cout << test(24) << endl;
    cout << test(100) << endl;

    return 0;
}

bool test(int numbers)
{
    if ((numbers % 10 <= 2) || (numbers % 10 >= 8))
        return true;
    return false;
}