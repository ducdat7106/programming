#include <iostream>

using namespace std;
bool test(int number);

int main()
{
    cout << test(21) << endl;
    cout << test(14) << endl;
    cout << test(3) << endl;
    cout << test(25) << endl;

    return 0;
}

bool test(int number)
{
    if ((number % 3 == 0 && number % 7 != 0) || (number % 3 != 0 && number % 7 == 0))
        return true;
    return false;
}