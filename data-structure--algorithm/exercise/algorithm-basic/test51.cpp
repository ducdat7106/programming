#include <iostream>
#include <string>

using namespace std;

int test(int x, int y);
int test_lib(int x, int y);

int main()
{
    cout << test(4, 5) << endl;
    cout << test(10, 10) << endl;
    cout << test(7, 4) << endl;

    return 0;
}

int counter_number_of_digit(int x)
{
    int counter = 0;
    while (x != 0)
    {
        counter++;
        x /= 10;
    }
    return counter;
}

int test(int x, int y)
{
    unsigned int sum = x + y;

    int len_sum = counter_number_of_digit(sum);
    int len_number = counter_number_of_digit(x);

    if (len_number == len_sum)
        return sum;
    else if (len_sum > len_number)
        return x;
}

int test_lib(int x, int y)
{
    return (to_string(x + y).length() > to_string(x).length()) ? x : x + y;
}