#include <iostream>

using namespace std;

int sum_integer(int number1, int number2);

int main()
{

    cout << sum_integer(1, 2) << endl;
    cout << sum_integer(3, 2) << endl;
    cout << sum_integer(2, 2) << endl;

    return 0;
}

int sum_integer(int number1, int number2)
{
    return (number1 == number2) ? (number1 + number2) * 3 : (number1 + number2);
}