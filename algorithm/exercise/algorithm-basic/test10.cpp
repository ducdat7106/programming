#include <iostream>

using namespace std;

bool test(unsigned int number);

int main()
{
    cout << test(3) << endl;
    cout << test(14) << endl;
    cout << test(7) << endl;
    cout << test(5) << endl;

    return 0;
}

bool test(unsigned int number)
{
    return number % 3 == 0 || number % 7 == 0;
}